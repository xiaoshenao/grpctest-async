# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# cmake build file for C++ IM.Login example.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building IM.Login.

cmake_minimum_required(VERSION 3.5.1)

project(IMLogin C CXX)

include(../cmake/common.cmake)

# Proto file
get_filename_component(im_proto "./IM.Login.proto" ABSOLUTE)
get_filename_component(im_proto_path "${im_proto}" PATH)

# Generated sources
set(im_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/IM.Login.pb.cc")
set(im_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/IM.Login.pb.h")
set(im_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/IM.Login.grpc.pb.cc")
set(im_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/IM.Login.grpc.pb.h")
# 根据proto文件生成.cc,.h
add_custom_command(
      OUTPUT "${im_proto_srcs}" "${im_proto_hdrs}" "${im_grpc_srcs}" "${im_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${im_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${im_proto}"
      DEPENDS "${im_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# im_grpc_proto
add_library(im_grpc_proto
  ${im_grpc_srcs}
  ${im_grpc_hdrs}
  ${im_proto_srcs}
  ${im_proto_hdrs})
target_link_libraries(im_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# Targets greeter_[async_](client|server)
foreach(_target
  client server server_async
  )
  add_executable(${_target} "${_target}.cc")
  target_link_libraries(${_target}
    im_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()
