//
// Created by zpb on 16-8-8.
//
#include "LinuxThread.h"

#ifdef __LINUX__



void LinuxThread::createNewThread(threadFunc func, void *arg) {
    pthread_create(&_threadID,nullptr,func,arg);
}

unsigned long LinuxThread::getThreadID() {
    return _threadID;
}



#endif