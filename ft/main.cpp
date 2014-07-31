#include <stdio.h>

#include "JsonRpc.h"
#include "trace.h"

#ifdef GTEST
int main_()
#else
int main()
#endif
{
    InfoMsg("main begin!\n");
    JsonRpc rpc;
    rpc.parse("{ \"id\":1}");
    rpc.print();

    InfoMsg("main end!\n");
    return 0;
}
