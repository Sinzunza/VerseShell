#ifndef __TESTCOMMAND_TESTS_HPP__
#define __TESTCOMMAND_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"


TEST(testCommandLiteralTests, noFlag) {
    base *indBase = new indConnector("test CMakeLists.txt");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, eFlagFile) {
    base *indBase = new indConnector("test -e CMakeLists.txt");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, eFlagDir) {  
    base* indBase = new indConnector("test -e images");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, fFlagFile) {
    base *indBase = new indConnector("test -f CMakeLists.txt");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, fFlagDir) {
    base *indBase = new indConnector("test -f images");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandLiteralTests, dFlagFile) {
    base *indBase = new indConnector("test -d CMakeLists.txt");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandLiteralTests, dFlagDir) {
    base *indBase = new indConnector("test -d images");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandSymbolicTests, noFlag) {
    base *indBase = new indConnector("[ CMakeLists.txt ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandSymbolicTests, eFlagFile) {
    base *indBase = new indConnector("[ -e CMakeLists.txt ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandSymbolicTests, eFlagDir) {
    base *indBase = new indConnector("[ -d images ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandSymbolicTests, fFlagFile) {
    base *indBase = new indConnector("[ -f CMakeLists.txt ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandSymbolicTests, fFlagDir) {
    base *indBase = new indConnector("[ -f images ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandSymbolicTests, dFlagFile) {
    base *indBase = new indConnector("[ -d CMakeLists.txt ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandSymbolicTests, dFlagDir) {
    base *indBase = new indConnector("[ -d images ]");
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

#endif
