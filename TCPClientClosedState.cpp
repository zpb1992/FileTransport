//
// Created by zpb on 16-8-1.
//

#include <sys/socket.h>
#include "TCPClientClosedState.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

int TCPClientClosedState::createSocket(int domain, int type, int protocol) {
 return socket(domain,type,protocol);
}

int TCPClientClosedState::connectTo(int socket, std::string ip, int port, int domain) {
 struct sockaddr_in servAddr;
 if(domain==AF_INET)
 {
  servAddr.sin_family=domain;
  servAddr.sin_port=htons(port);
  servAddr.sin_addr.s_addr=inet_addr(ip.c_str());
 }
 return connect(socket,(sockaddr*)&servAddr,sizeof(sockaddr_in));
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

















