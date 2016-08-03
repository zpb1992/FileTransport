//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPSERVERESTABLISHEDSTATE_H
#define FILETRANSPORT_TCPSERVERESTABLISHEDSTATE_H

#include "TCPServerState.h"

class TCPServerEstablishedState:public TCPServerState {
public:
    int createSocket(int domain, int type, int protocol) override ;

    int bindTo(int socket,std::string ip,int port,int domain) override ;

    int lisenTo(int socket,int backlog) override ;

    int acceptConnect(int socket,std::string &ip,int &port) override ;

    int receiveFrom(int socket,std::string file) override ;

    int sendTo(int socket,std::string file) override ;

    int closeSocket(int socket) override ;
};


#endif //FILETRANSPORT_TCPSERVERESTABLISHEDSTATE_H
