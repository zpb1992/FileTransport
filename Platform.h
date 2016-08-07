//
// Created by zpb on 16-8-7.
//

#ifndef FILETRANSPORT_PLATFORM_H
#define FILETRANSPORT_PLATFORM_H

#if (defined(__linux__)|| defined(__linux))
#define __LINUX__
#endif

#ifdef WIN32
#define __WINDOWS__
#endif

#endif //FILETRANSPORT_PLATFORM_H
