#include "gtest/gtest.h"

#include "../src/indConnector_tests.hpp"
#include "../src/orConnector_tests.hpp"
#include "../src/andConnector_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
