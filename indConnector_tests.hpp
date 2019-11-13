#ifndef __INDCONNECTOR_TESTS_HPP__
#define __INDCONNECTOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "indConnector.hpp"

TEST(indConnectorTest, using_echo) {
    std::string cmdOne = "echo";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    std::string argOne = "Hello World";
    char *charTwo = const_cast<char*>(argOne.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->getSucceeded(), true);
}


TEST(indConnectorTest, using_touch) {
    std::string cmdOne = "touch";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    std::string argOne = "aFile.cpp";
    char *charTwo = const_cast<char*>(argOne.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
	
    EXPECT_EQ(indBase->getSucceeded(), true);
}

TEST(indConnectorTest, using_ls) {
    std::string cmdOne = "ls";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    char *charAr[2] = {charOne,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();

    EXPECT_EQ(indBase->getSucceeded(), true);
}

#endif
