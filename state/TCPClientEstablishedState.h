//
// Created by zpb on 16-8-1.
//

#ifndef FILETRANSPORT_TCPCLIENTESTABLISHEDSTATE_H
#define FILETRANSPORT_TCPCLIENTESTABLISHEDSTATE_H

#include "TCPClientState.h"

class TCPClientEstablishedState:public TCPClientState {
public:
    int createSocket(int domain, int type, int protocol) override ;

    int connectTo(int socket,std::string ip,unsigned short port,int domain) override ;

    virtual int receiveFrom(int socket,std::string file) override ;

    virtual int sendTo(int socket,std::string file) override ;

    int closeSocket(int socket) override ;

};

#endif //FILETRANSPORT_TCPCLIENTESTABLISHEDSTATE_H
