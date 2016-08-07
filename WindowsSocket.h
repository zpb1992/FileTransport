//
// Created by zpb on 16-8-4.
//

#include "PlatformSocket.h"

#ifdef __WINDOWS__

#ifndef FILETRANSPORT_WINDOWSSOCKET_H
#define FILETRANSPORT_WINDOWSSOCKET_H

#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>

class WindowsSocket :public PlatformSocket{
public:
    int init() override ;

    int createSocket(int domain, int type, int protocol) override;

    int connectTo(int socket, const struct sockaddr *name, int namelen) override;

    int bindTo(int socket, const struct sockaddr *addr, int addrlen) override;

    int listenOn(int socket, int backlog) override;

    int acceptFrom(int socket, struct sockaddr *addr, int *addrLen) override;

    int sendTo(int socket, void *buffer, int len, int flags) override;

    int recvFrom(int socket, void *buffer, int len, int flags) override;

    int closeSocket(int socket) override ;

    int cleanup() override;

    unsigned short hostToNet16(unsigned short num) override;

    unsigned hostToNet32(unsigned num) override;

    unsigned short netToHost16(unsigned short num) override;

    unsigned netToHost32(unsigned num) override;

    unsigned getAddrNum(const char *ip) override;

    std::string getAddrStr(in_addr in) override;

};


#endif //FILETRANSPORT_WINDOWSSOCKET_H


#endif