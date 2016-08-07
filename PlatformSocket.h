//
// Created by zpb on 16-8-4.
//

#ifndef FILETRANSPORT_PLATFORMSOCKET_H
#define FILETRANSPORT_PLATFORMSOCKET_H


#include "Platform.h"

#include <string>

class PlatformSocket {
public:
    virtual int init() = 0;

    virtual int createSocket(int domain, int type, int protocol) = 0;

    virtual int connectTo(int socket, short family,std::string ip,unsigned short port) = 0;

    virtual int bindTo(int socket, short family,std::string ip,unsigned short port) = 0;

    virtual int listenOn(int socket, int backlog) = 0;

    virtual int acceptFrom(int socket, int family,std::string &ip,unsigned short &port) = 0;

    virtual int sendTo(int socket, void *buffer, int len, int flags) = 0;

    virtual int recvFrom(int socket, void *buffer, int len, int flags) = 0;

    virtual int closeSocket(int socket) = 0;

    virtual int cleanup() = 0;

    virtual unsigned short hostToNet16(unsigned short num) = 0;

    virtual unsigned hostToNet32(unsigned num) = 0;

    virtual unsigned short netToHost16(unsigned short num) = 0;

    virtual unsigned netToHost32(unsigned num) = 0;

    virtual unsigned getAddrNum(const char *ip) = 0;

    virtual std::string getAddrStr(unsigned in) = 0;



};


#endif //FILETRANSPORT_PLATFORMSOCKET_H
