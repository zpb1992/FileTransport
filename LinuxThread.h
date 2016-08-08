//
// Created by zpb on 16-8-8.
//
#include "PlatformThread.h"

#ifdef __LINUX__

#ifndef FILETRANSPORT_LINUXTHREAD_H
#define FILETRANSPORT_LINUXTHREAD_H

#include <pthread.h>

class LinuxThread :public PlatformThread {
public:
    void createNewThread(threadFunc,void *arg) override ;
    unsigned long getThreadID() override ;
};


#endif //FILETRANSPORT_LINUXTHREAD_H


#endif