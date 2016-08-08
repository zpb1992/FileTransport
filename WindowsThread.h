//
// Created by zpb on 16-8-8.
//

#include "PlatformThread.h"


#ifdef __WINDOWS__

#ifndef FILETRANSPORT_WINDOWSTHREAD_H
#define FILETRANSPORT_WINDOWSTHREAD_H


#include <windows.h>
#include <process.h>

class WindowsThread :public PlatformThread  {
public:
    void createNewThread(threadFunc,void *arg) override ;
    unsigned long getThreadID() override ;

};


#endif //FILETRANSPORT_WINDOWSTHREAD_H

#endif