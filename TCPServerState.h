//
// Created by zpb on 16-7-29.
//

#ifndef FILETRANSPORT_TCPSERVERSTATE_H
#define FILETRANSPORT_TCPSERVERSTATE_H

#include "TCPState.h"

class TCPServerState :public TCPState{
public:
    virtual int createSocket(int domain, int type, int protocol) = 0;

    virtual int bindTo(int socket,std::string ip,unsigned short port,int domain) =0 ;

    virtual int lisenTo(int socket, int backlog) = 0;

    virtual int acceptConnect(int socket,std::string &addr,unsigned short &port) = 0;

    virtual int receiveFrom(int socket,std::string file)=0;

    virtual int sendTo(int socket,std::string file)=0;

    virtual int closeSocket(int socket) = 0;
};


#endif //FILETRANSPORT_TCPSERVERSTATE_H
