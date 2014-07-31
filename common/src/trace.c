/*
 * trace.c
 *
 *  Created on: 2012-2-29
 *      Author: jianmink
 */

#include "trace.h"

char mTraceMap=1;


//int
//checkTraceMap()
//{
//	return mTraceMap;
//}

void
turnOnTrace()
{
	mTraceMap=1;
}

void
turnOffTrace()
{
	mTraceMap=0;
}
