#include "gmock/gmock.h"
#include <string.h>
#include "gtest/gtest.h"

using testing::GMOCK_FLAG(verbose);
using testing::InitGoogleMock;
using testing::internal::g_init_gtest_count;

#include <stdio.h>

#include "JsonRpc.h"

class TestJsonRpc: public testing::Test
{
protected:
};


TEST_F(TestJsonRpc,parse)
{

    JsonRpc rpc;
    bool rtn=rpc.parse("{ \"params\":{ \"name\": \"jimi\"},  \"jsonrpc\": \"2.0\", \"method\": \"demo\", \"id\":1}");

    rpc.run();

    ASSERT_TRUE(rtn);
}



