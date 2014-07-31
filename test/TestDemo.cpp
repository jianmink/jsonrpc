#include "gmock/gmock.h"
#include <string.h>
#include "gtest/gtest.h"

using testing::GMOCK_FLAG(verbose);
using testing::InitGoogleMock;
using testing::internal::g_init_gtest_count;

#include <stdio.h>

#include "demo.h"

class TestDemo: public testing::Test
{
protected:
};


TEST_F(TestDemo,demo)
{
    ASSERT_EQ(1,demo());
}



