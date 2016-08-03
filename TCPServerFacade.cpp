//
// Created by zpb on 16-8-3.
//

#include "TCPServerFacade.h"

TCPServerFacade::TCPServerFacade() {
    _server=new TCPServer();
    _server->createSocket(AF_INET,SOCK_STREAM,0);
}

void TCPServerFacade::waitConnect(int port, std::string ip) {
    _server->bindAddr(ip,port);
    _server->listenTo(1);
    _server->acceptConnection();
}

void TCPServerFacade::closeConnection() {
    _server->close();
    delete _server;
}
