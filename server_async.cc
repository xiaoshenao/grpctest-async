#include <iostream>
#include <memory>
#include <string>


#include "IM.Login.grpc.pb.h"
#include "IM.Login.pb.h"

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

// 自己proto文件的命名空间
using IM::Login::ImLogin;
using IM::Login::IMLoginReq;
using IM::Login::IMLoginRes;
using IM::Login::IMRegistReq;
using IM::Login::IMRegistRes;

class ServerImpl final{
public:
   ~ServerImpl(){
      server_->Shutdown();

      cq_->Shutdown();
   }

   void Run(){
     std::string server_addr("0.0.0.0:50051");
     ServerBuilder builder;
     builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
     builder.RegisterService(&service_);
     cq_=builder.AddCompletionQueue();
     server_=builder.BuildAndStart();
     std::cout<<"Server listening on:"<<server_addr<<std::endl;

     HanderRpcs();
   }


private:
   class CallData{
   public:
        CallData(ImLogin::AsyncService* service,ServerCompletionQueue* cq)
           :service_(service),cq_(cq),status_(CREATE){
            std::cout<<"CallData constucting,this:"<<this<<std::endl;
            Proceed();
        }
        virtual ~CallData(){}
        virtual void Proceed(){
            //std::cout<<"CallData Prooceed"<<std::endl;
            return;
        }

        ImLogin::AsyncService* service_;
        ServerCompletionQueue* cq_;
        ServerContext ctx_;
        enum CallStatus {CREATE,PROCESS,FINISH};
        CallStatus status_;
   };

   class RegistCallData:public CallData{
    public:
        RegistCallData(ImLogin::AsyncService* service,ServerCompletionQueue* cq)
          :CallData(service,cq),responder_(&ctx_){
           Proceed();
        }
        ~RegistCallData()override{}
        void Proceed()override{
            std::cout<<"this:"<<this
                     <<"RegistCallData Proceed(),status:"<<status_
                     <<std::endl;
            if(status_==CREATE){
                std::cout<<"this:"<<this<<"RegistCallData Proceed(),status:"
                         <<"CREATE"<<std::endl;
                status_=PROCESS;

                service_->RequestRegist(&ctx_,&request_,&responder_,cq_,cq_,this);
            }else if(status_==PROCESS){
                std::cout<<"this:"<<this<<"RegistData Proceed(),status:"
                         <<"PROCESS"<<std::endl;

                new RegistCallData(service_,cq_);

                response_.set_user_name(request_.user_name());
                response_.set_user_id(10);
                response_.set_result_code(0);

                status_=FINISH;
                responder_.Finish(response_,Status::OK,this);

            }else{
                std::cout<<"this:"<<this<<"RegistCallData Proceed(),status:"
                         <<"FINISH"<<std::endl;
                GPR_ASSERT(status_==FINISH);

                delete this;
            }
        }


    private:
        IMRegistReq request_;
        IMRegistRes response_;
        ServerAsyncResponseWriter<IMRegistRes>responder_;
   };
   
   class LoginCallData:public CallData{
    public:
        LoginCallData(ImLogin::AsyncService* service,ServerCompletionQueue* cq)
          :CallData(service,cq),responder_(&ctx_){
          Proceed(); 
        }
        ~LoginCallData()override{}
        void Proceed()override{
            std::cout<<"this:"<<this
                     <<"LoginCallData Proceed(),status:"<<status_
                     <<std::endl;
            if(status_==CREATE){
                std::cout<<"this:"<<this<<"LoginCallData Proceed(),status:"
                         <<"CREATE"<<std::endl;
                status_=PROCESS;

                service_->RequestLogin(&ctx_,&request_,&responder_,cq_,cq_,this);
            }else if(status_==PROCESS){
                std::cout<<"this:"<<this<<"LoginData Proceed(),status:"
                         <<"PROCESS"<<std::endl;

                new LoginCallData(service_,cq_);

                
                response_.set_user_id(10);
                response_.set_result_code(0);

                status_=FINISH;
                responder_.Finish(response_,Status::OK,this);

            }else{
                std::cout<<"this:"<<this<<"LoginCallData Proceed(),status:"
                         <<"FINISH"<<std::endl;
                GPR_ASSERT(status_==FINISH);

                delete this;
            }
        }


    private:
        IMLoginReq request_;
        IMLoginRes response_;
        ServerAsyncResponseWriter<IMLoginRes>responder_;
   };

   void HanderRpcs(){
     new RegistCallData(&service_,cq_.get());
     new LoginCallData(&service_,cq_.get());

     void* tag;
     bool ok;
     while(true){
        std::cout<<"before cq_->Next"
                 <<std::endl;
        GPR_ASSERT(cq_->Next(&tag,&ok));
        std::cout<<"after cq_->Next"<<std::endl;
        GPR_ASSERT(ok);
        std::cout<<"before static_cast"<<std::endl;
        static_cast<CallData*>(tag)->Proceed();
        std::cout<<"after static_cast"<<std::endl;
     }
   }

   std::unique_ptr<ServerCompletionQueue>cq_;
   ImLogin::AsyncService service_;
   std::unique_ptr<Server>server_;
};

int main(){
    ServerImpl server;
    server.Run();
    return 0;
}

