//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPSERVERLISTENSTATE_H
#define FILETRANSPORT_TCPSERVERLISTENSTATE_H

#include "TCPServerState.h"


class TCPServerListenState :public TCPServerState{
public:
    int createSocket(int domain, int type, int protocol) override ;

    int bindTo(int socket,std::string ip,unsigned short port,int domain) override ;

    int lisenTo(int socket,int backlog) override ;

    virtual int acceptConnect(int socket,std::string &addr,unsigned short &port) override ;

    int receiveFrom(int socket,std::string file) override ;

    int sendTo(int socket,std::string file) override ;

    int closeSocket(int socket) override ;
};


#endif //FILETRANSPORT_TCPSERVERLISTENSTATE_H
