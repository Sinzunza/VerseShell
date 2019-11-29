#ifndef __INDCONNECTOR_TESTS_HPP__
#define __INDCONNECTOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"


TEST(indConnectorTest, using_echo) {
    base *indBase = new indConnector("echo Hello World");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(indConnectorTest, using_ls) {
    base *indBase = new indConnector("ls");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), true);
}

#endif
