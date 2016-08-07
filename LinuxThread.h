//
// Created by zpb on 16-8-8.
//
#include "PlatformThread.h"


#ifndef FILETRANSPORT_LINUXTHREAD_H
#define FILETRANSPORT_LINUXTHREAD_H


class LinuxThread :public PlatformThread {
public:
    void createNewThread(void *(*func)(void *),void *arg) override ;
    unsigned long getThreadID() override ;
};


#endif //FILETRANSPORT_LINUXTHREAD_H
