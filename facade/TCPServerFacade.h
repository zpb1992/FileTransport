//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPSERVERFACADE_H
#define FILETRANSPORT_TCPSERVERFACADE_H

#include "TCPServer.h"

class TCPServerFacade {
public:
    TCPServerFacade();
    void waitConnect(unsigned short port,std::string ip="0.0.0.0");
    void closeConnection();

private:
    TCPServer *_server;
};


#endif //FILETRANSPORT_TCPSERVERFACADE_H
