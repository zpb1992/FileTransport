//
// Created by zpb on 16-8-7.
//

#ifndef FILETRANSPORT_PLATFORMTHREAD_H
#define FILETRANSPORT_PLATFORMTHREAD_H

#include "Platform.h"


class PlatformThread {
public:
#if defined __WINDOWS__
	typedef unsigned int(_stdcall *threadFunc)(void *);
#elif defined __LINUX__
	typedef void *(* threadFunc)(void *);
#endif

public:
    virtual void createNewThread(threadFunc,void *arg)=0;
    virtual unsigned long getThreadID()=0;

protected:
    unsigned long _threadID;

};


#endif //FILETRANSPORT_PLATFORMTHREAD_H
