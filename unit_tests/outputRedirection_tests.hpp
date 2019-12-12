#ifndef __OUTPUTREDIRECTION_TESTS_HPP__
#define __OUTPUTREDIRECTION_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"


TEST(outputRedirectionTest, singleInput) {
    base *createFile = new indConnector("touch aFile.txt");
    createFile->execute();
    base *indBase = new indConnector("echo hello > aFile.txt");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(outputRedirectionTest, singleInputFail) {
    base *indBase = new indConnector("echh hello > aFile.txt ");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(outputRedirectionAppendTest, singleInput) {
    base *indBase = new indConnector("echo hello >> aFile.txt");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(outputRedirectionAppendTest, singleInputFail) {
    base *indBase = new indConnector("echh hello > aFile.txt ");
    indBase->execute();

    EXPECT_EQ(indBase->isSuccessful(), false);
    base *deleteFile = new indConnector("rm aFile.txt");
    deleteFile->execute();
}

#endif
