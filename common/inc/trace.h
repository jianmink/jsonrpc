/*
 * trace.h
 *
 *  Created on: 2012-2-29
 *      Author: jianmink
 */

#ifndef MY_TRACE_H_
#define MY_TRACE_H_

#include <stdio.h>

extern char mTraceMap;
#define checkTraceMap() mTraceMap

#define  ErrMsg(format,...) \
		do{\
			if(checkTraceMap()){ \
				fprintf(stderr,"%-20.20s:%5d- " format,__FILE__, __LINE__,##__VA_ARGS__);\
			}\
		}while(0)

#define  WarningMsg(format,...) \
		do{\
			if(checkTraceMap()){ \
			fprintf(stderr,"%-20.20s:%5d- " format,__FILE__, __LINE__,##__VA_ARGS__);\
			}\
		}while(0)

#define  PrintMsg(format,...) \
		do{\
			if(checkTraceMap()){ \
			fprintf(stdout,"%-20.20s:%5d- " format,__FILE__, __LINE__,##__VA_ARGS__);\
			}\
		}while(0)

#define  InfoMsg(format,...) \
		do{\
			if(checkTraceMap()){ \
			fprintf(stderr, "%-20.20s:%5d- " format,__FILE__, __LINE__,##__VA_ARGS__);\
			}\
		}while(0)

void turnOnTrace();
void turnOffTrace();

#endif /* TRACE_H_ */
