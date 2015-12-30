#ifndef _k_LOG_h_
#define _k_LOG_h_

#include <stdio.h>

#define kLOG(format, ...) printf("kLOG:%s(%d)%s:" format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#endif

