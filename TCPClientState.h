//
// Created by zpb on 16-7-29.
//

#ifndef FILETRANSPORT_TCPCLIENTSTATE_H
#define FILETRANSPORT_TCPCLIENTSTATE_H

#include<string>
#include "TCPState.h"

class TCPClientState : public TCPState {
public:
    virtual int createSocket(int domain, int type, int protocol) = 0;

    virtual int connectTo(int socket,std::string ip,int port,int domain) = 0;

    virtual int receiveFrom(int socket,std::string file)=0;

    virtual int sendTo(int socket,std::string file)=0;

    virtual int closeSocket(int socket) = 0;

    
};


#endif //FILETRANSPORT_TCPCLIENTSTATE_H
