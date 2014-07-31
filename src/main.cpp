#include <stdio.h>

#include "demo.h"
#include "trace.h"

#ifdef GTEST
int main_()
#else
int main()
#endif
{
    InfoMsg("main begin!\n");
    demo();
    InfoMsg("main end!\n");
    return 0;
}
