#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/channel.h>
#include <grpcpp/grpcpp.h>

#include "IM.Login.pb.h"
#include "IM.Login.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

//自己的
using IM::Login::ImLogin;
using IM::Login::IMLoginReq;
using IM::Login::IMLoginRes;
using IM::Login::IMRegistReq;
using IM::Login::IMRegistRes;



class ImLoginClient{
public:
   explicit ImLoginClient(std::shared_ptr<Channel>channel)
       :stub_(ImLogin::NewStub(channel)){
    }
    void Regist(const std::string& user_name,const std::string &password){
        IMRegistReq request;
        request.set_user_name(user_name);
        request.set_password(password);

        IMRegistRes response;
        ClientContext context;
        Status status=stub_->Regist(&context, request, &response);
        if(status.ok()){
            std::cout<<"user_name:"<<response.user_name()<<",user_id:"<<response.user_id()<<std::endl;
           
        }else{
            std::cout<<"user_name:"<<response.user_name()<<",Regist failed:"<<response.result_code()<<std::endl;
        }
    }

    void Login(const std::string& user_name,const std::string &password){
        IMLoginReq request;
        request.set_user_name(user_name);
        request.set_password(password);

        IMLoginRes response;
        ClientContext context;
        std::cout<<"->Login req"<<std::endl;
        Status status=stub_->Login(&context, request, &response);
        if(status.ok()){
            std::cout<<"user_id:"<<response.user_id()<<",Login ok"<<std::endl;
           
        }else{
            std::cout<<"user_name:"<<request.user_name()<<",Login failed:"<<response.result_code()<<std::endl;
        }
    }
private:
    std::unique_ptr<ImLogin::Stub>stub_;


};


int main(){
    //服务器地址
    std::string server_addr="0.0.0.0:50051";
    ImLoginClient im_login_client(
        grpc::CreateChannel(server_addr,grpc::InsecureChannelCredentials())
    );
    std::string user_name="shenao";
    std::string password="123456";
    im_login_client.Regist(user_name,password);
    im_login_client.Login(user_name,password);

    return 0;
}
