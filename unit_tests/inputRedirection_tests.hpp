#ifndef __INPUTREDIRECTION_TESTS_HPP__
#define __INPUTREDIRECTION_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"


TEST(inputRedirectionTest, singleInput) {
    base *indBase = new indConnector("cat < names.txt");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(inputRedirectionTest, singleInputFail) {
    base *indBase = new indConnector("cattt < names.txt ");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), false);
}

#endif
