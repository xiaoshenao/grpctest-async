#include<iostream>
#include<string>

//grpc头文件
#include <grpcpp/completion_queue.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>

//包含自己生成的.h
#include "IM.Login.pb.h"
#include "IM.Login.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

//自己的
using IM::Login::ImLogin;
using IM::Login::IMLoginReq;
using IM::Login::IMLoginRes;
using IM::Login::IMRegistReq;
using IM::Login::IMRegistRes;

class IMloginServiceImpl :public ImLogin::Service{
    //注册
     Status Regist(ServerContext* context, const IMRegistReq* request, IMRegistRes* response) override {
         std::cout<<"Regist"<<request->user_name()<<std::endl;
         response->set_user_name(request->user_name());
         response->set_user_id(10);
         response->set_result_code(0);
         return Status::OK;
    }
    
    //登录
     Status Login(ServerContext* context, const IMLoginReq* request, IMLoginRes* response) override {
        std::cout<<"Login user_name"<<request->user_name()<<std::endl;
        response->set_user_id(10);
         response->set_result_code(0);
         return Status::OK;
    }
  
};

void Runserver(){
    std::string server_addr("0.0.0.0:50051");
    //创建一个服务类
    IMloginServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
    builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_TIME_MS,5000);
    builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_TIMEOUT_MS, 10000);
    builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_PERMIT_WITHOUT_CALLS, 1);
    builder.RegisterService(&service);

    //创建启动

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout<<"Server listening on"<<server_addr<<std::endl;

    //进入服务循环
    server->Wait();
}


int main(){
    Runserver();
    return 0;
}