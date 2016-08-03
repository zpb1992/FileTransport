//
// Created by zpb on 16-8-1.
//

#ifndef FILETRANSPORT_TCPCLIENTCLOSEDSTATE_H
#define FILETRANSPORT_TCPCLIENTCLOSEDSTATE_H

#include "TCPClientState.h"

class TCPClientClosedState:public TCPClientState {
public:
    int createSocket(int domain, int type, int protocol) override ;

    int connectTo(int socket,std::string ip,int port,int domain) override ;

    virtual int receiveFrom(int socket,std::string file) override ;

    virtual int sendTo(int socket,std::string file) override ;

    int closeSocket(int socket) override ;
};


#endif //FILETRANSPORT_TCPCLIENTCLOSEDSTATE_H
