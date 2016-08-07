//
// Created by zpb on 16-8-1.
//

#include "TCPClientClosedState.h"

int TCPClientClosedState::createSocket(int domain, int type, int protocol) {
 return _platform->createSocket(domain,type,protocol);
}

int TCPClientClosedState::connectTo(int socket, std::string ip, unsigned short port, int domain) {
 return _platform->connectTo(socket,domain,ip,port);
}


int TCPClientClosedState::closeSocket(int socket) {
 std::cout << "TCP Client state is Closed, can not close" << std::endl;

 return -1;
}

int TCPClientClosedState::receiveFrom(int socket, std::string file) {
 std::cout << "TCP Client state is Closed, can not recv" << std::endl;
 return -1;
}

int TCPClientClosedState::sendTo(int socket, std::string file) {
 std::cout << "TCP Client state is Closed, can not send" << std::endl;
 return -1;
}

















