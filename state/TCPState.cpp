//
// Created by zpb on 16-7-29.
//

#include <cmath>
#include <cassert>
#include "TCPState.h"


#if (defined(__LINUX__))
PlatformSocket *TCPState::_platform=new LinuxSocket();
#elif (defined(__WINDOWS__))
PlatformSocket *TCPState::_platform=new WindowsSocket();
#else
PlatformSocket *TCPState::_platform=nullptr;
#endif

void TCPState::init()
{
	_platform->init();
}

void TCPState::cleanup()
{
	_platform->cleanup();
}


int TCPState::recvFrom(int socket, void *data, int len) {
    return _platform->recvFrom(socket,data,len,0);
}

int TCPState::sendTo(int socket, void *data, int len) {
    return _platform->sendTo(socket, data, len, 0);
}

int TCPState::recvFile(int socket, std::string file) {
    std::ofstream ofs(file,std::ios_base::binary|std::ofstream::trunc);
    char *buffer=new char[BUFFER_MAX];

    unsigned fileLen=recvUint32(socket);

    unsigned recvedLen=0;
    while(recvedLen<fileLen)
    {
        unsigned tempBufLen=BUFFER_MAX<(fileLen-recvedLen)?BUFFER_MAX:(fileLen-recvedLen);
        recvedLen+=_platform->recvFrom(socket,buffer,tempBufLen,0);

        ofs.write(buffer,recvedLen);
    }

    ofs.close();


    return fileLen;
}

int TCPState::sendFile(int socket, std::string file) {
    std::ifstream ifs(file,std::ios_base::binary);
    unsigned fileLen = _platform->hostToNet32(getFileLength(ifs));
    char *buffer = new char[BUFFER_MAX];

    _platform->sendTo(socket,&fileLen,sizeof(unsigned),0);
    fileLen=_platform->netToHost32(fileLen);    //?

    while (ifs)
    {
        ifs.read(buffer,BUFFER_MAX);
        int realReadLen=(int)ifs.gcount();
        _platform->sendTo(socket, buffer,realReadLen, 0);
    }

    ifs.close();

    return fileLen;
}

unsigned TCPState::getFileLength(std::ifstream &ifs) {
    assert(ifs);
    unsigned result;
    ifs.seekg(0, std::ios_base::end);
    result= (unsigned) ifs.tellg();
    ifs.seekg(0,std::ios_base::beg);
    return result;
}

long long TCPState::getFileLength(std::ofstream &ofs) {
    long long result;
    ofs.seekp(0, std::ios_base::end);
    result=ofs.tellp();
    ofs.seekp(0,std::ios_base::beg);
    return result;
}

void TCPState::numToChar(long long num, char *buffer, int len) {
    int index=0;
    while(num!=0)
    {
        buffer[index]=(char)(num%256);
        num=num>>8;
        ++index;
    }
}

long long TCPState::charToNum(char *buffer, int len) {
    long long result=0;
    int index=0;
    while(index<len)
    {
        result+=buffer[index]*pow(256,index);
        ++index;
    }
    return result;
}

unsigned TCPState::recvUint32(int socket) {
    unsigned result; // network zijiexu
    int recvLen=_platform->recvFrom(socket,&result,sizeof(result),0);
    assert(recvLen==sizeof(result));
    return _platform->netToHost32(result);
}









