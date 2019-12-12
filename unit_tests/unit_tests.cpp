#include "gtest/gtest.h"

#include "indConnector_tests.hpp"
#include "orConnector_tests.hpp"
#include "andConnector_tests.hpp"
#include "testCommand_tests.hpp"
#include "inputRedirection_tests.hpp"
#include "outputRedirection_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
