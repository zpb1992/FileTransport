cmake_minimum_required(VERSION 3.5)
project(FileTransport)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TCPClient.cpp TCPClient.h TCPServer.cpp TCPServer.h TCPState.cpp TCPState.h TCPClientState.cpp TCPClientState.h TCPServerState.cpp TCPServerState.h TCPClientClosedState.cpp TCPClientClosedState.h TCPClientEstablishedState.cpp TCPClientEstablishedState.h TCPClient.cpp TCPClient.h TCPServerClosedState.cpp TCPServerClosedState.h TCPServerEstablishedState.cpp TCPServerEstablishedState.h TCPServerListenState.cpp TCPServerListenState.h TCPServer.cpp TCPServer.h TCPConnection.cpp TCPConnection.h)

add_executable(FileTransport ${SOURCE_FILES})

target_link_libraries(FileTransport pthread)