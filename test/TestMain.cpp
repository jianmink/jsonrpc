#include "gmock/gmock.h"

#include <string.h>
#include "gtest/gtest.h"

using testing::GMOCK_FLAG(verbose);
using testing::InitGoogleMock;
using testing::internal::g_init_gtest_count;

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}

