//
// Created by zpb on 16-8-1.
//

#include "TCPClientEstablishedState.h"


int TCPClientEstablishedState::createSocket(int domain, int type, int protocol) {
    std::cout << "TCP Client state is Established, can not create socket" << std::endl;
    return -1;
}

int TCPClientEstablishedState::connectTo(int socket, std::string ip,unsigned short port,int domain) {
    std::cout << "TCP Client state is Established, can not connect" << std::endl;
    return -1;
}



int TCPClientEstablishedState::closeSocket(int socket) {
    _platform->closeSocket(socket);
    return 0;
}

int TCPClientEstablishedState::receiveFrom(int socket, std::string file) {
    return recvFile(socket,file);
}

int TCPClientEstablishedState::sendTo(int socket, std::string file) {
    return sendFile(socket,file);
}















