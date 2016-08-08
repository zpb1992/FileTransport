//
// Created by zpb on 16-8-8.
//

#include "WindowsThread.h"

#ifdef __WINDOWS__


void WindowsThread::createNewThread(threadFunc func,void *arg)
{
	_beginthreadex(nullptr,0,func,arg,0,nullptr);
}

unsigned long WindowsThread::getThreadID()
{
	_threadID=GetCurrentThreadId();
	return _threadID;
}

#endif
