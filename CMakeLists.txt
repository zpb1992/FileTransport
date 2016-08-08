cmake_minimum_required(VERSION 3.5)
project(FileTransport)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/connect ${PROJECT_SOURCE_DIR}/facade ${PROJECT_SOURCE_DIR}/platform ${PROJECT_SOURCE_DIR}/state)

AUX_SOURCE_DIRECTORY(./connect CONNECT_SRCS)
AUX_SOURCE_DIRECTORY(./facade FACADE_SRCS)
AUX_SOURCE_DIRECTORY(./platform PLATFORM_SRCS)
AUX_SOURCE_DIRECTORY(./state STATE_SRCS)
AUX_SOURCE_DIRECTORY(. MAIN_SRCS)

set(SOURCE_FILES ${FACADE_SRCS} ${CONNECT_SRCS} ${PLATFORM_SRCS} ${STATE_SRCS} ${MAIN_SRCS})
#set(SOURCE_FILES main.cpp TCPClient.cpp TCPClient.h TCPServer.cpp TCPServer.h TCPState.cpp TCPState.h TCPClientState.cpp TCPClientState.h TCPServerState.cpp TCPServerState.h TCPClientClosedState.cpp TCPClientClosedState.h TCPClientEstablishedState.cpp TCPClientEstablishedState.h TCPClient.cpp TCPClient.h TCPServerClosedState.cpp TCPServerClosedState.h TCPServerEstablishedState.cpp TCPServerEstablishedState.h TCPServerListenState.cpp TCPServerListenState.h TCPServer.cpp TCPServer.h TCPConnection.cpp TCPConnection.h TCPClientFacade.cpp TCPClientFacade.h TCPServerFacade.cpp TCPServerFacade.h PlatformSocket.cpp PlatformSocket.h WindowsSocket.cpp WindowsSocket.h LinuxSocket.cpp LinuxSocket.h PlatformThread.cpp PlatformThread.h Platform.h LinuxThread.cpp LinuxThread.h WindowsThread.cpp WindowsThread.h)

add_executable(FileTransport ${SOURCE_FILES})

target_link_libraries(FileTransport pthread)
