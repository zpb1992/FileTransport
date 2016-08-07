//
// Created by zpb on 16-8-8.
//
#include "LinuxThread.h"

#ifdef __LINUX__

#include <pthread.h>

void LinuxThread::createNewThread(void *(*func)(void *), void *arg) {
    pthread_create(&_threadID,nullptr,func,arg);
}

unsigned long LinuxThread::getThreadID() {
    return _threadID;
}



#endif