//
// Created by zpb on 16-8-7.
//

#ifndef FILETRANSPORT_PLATFORMTHREAD_H
#define FILETRANSPORT_PLATFORMTHREAD_H

#include "Platform.h"

class PlatformThread {
public:
    virtual void createNewThread(void *(*func)(void *),void *arg)=0;
    virtual unsigned long getThreadID()=0;

protected:
    unsigned long _threadID;

};


#endif //FILETRANSPORT_PLATFORMTHREAD_H
