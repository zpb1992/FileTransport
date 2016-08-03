//
// Created by zpb on 16-8-3.
//

#include "TCPClientFacade.h"

TCPClientFacade::TCPClientFacade() {
    _client=new TCPClient();
    _client->createSocket(AF_INET,SOCK_STREAM,0);
}

void TCPClientFacade::sendFile(std::string file) {
    _client->send(file);
}

void TCPClientFacade::closeConnection() {
    _client->closeSocket();
    delete _client;
}

void TCPClientFacade::connectTo(std::string ip, int port) {
    _client->connect(ip,port);
}

void TCPClientFacade::recvFile(std::string file) {
    _client->recv(file);
}









