#ifndef __ANDCONNECTOR_TESTS_HPP__
#define __ANDCONNECTOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"
#include "../src/orConnector.hpp"
#include "../src/andConnector.hpp"


TEST(andConnectorTests, using_echo_succeeded) {
    std::string cmdOneOr = "echo";
    char *charOneOr = const_cast<char*>(cmdOneOr.c_str());
    std::string argOneOr = "Hello World";
    char *charTwoOr = const_cast<char*>(argOneOr.c_str());
    char *charArOr[3] = {charOneOr,charTwoOr,NULL};
    base *indBase = new indConnector(charArOr);
    indBase->execute();

    std::string cmdOne = "echo";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    std::string argOne = "Hello World Two";
    char *charTwo = const_cast<char*>(argOne.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *andBase = new andConnector(indBase, charAr);
    andBase->execute();

    EXPECT_EQ(andBase->isSuccessful(), true);
}

TEST(andConnectorTests, using_echo_not_succeeded) {
    std::string cmdOneOr = "fdgjk";
    char *charOneOr = const_cast<char*>(cmdOneOr.c_str());
    std::string argOneOr = "Hello World";
    char *charTwoOr = const_cast<char*>(argOneOr.c_str());
    char *charArOr[3] = {charOneOr,charTwoOr,NULL};
    base *indBase2 = new indConnector(charArOr);
    indBase2->execute();

    std::string cmdOne = "echo";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    std::string argOne = "Hello World Two";
    char *charTwo = const_cast<char*>(argOne.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *andBase2 = new andConnector(indBase2, charAr);
    andBase2->execute();

    EXPECT_EQ(andBase2->isSuccessful(),false);
}


TEST(andConnectorTests, using_echo_succeeded_allConnectors) {
    std::string cmdOneOr = "echo";
    char *charOneOr = const_cast<char*>(cmdOneOr.c_str());
    std::string argOneOr = "Hello World";
    char *charTwoOr = const_cast<char*>(argOneOr.c_str());
    char *charArOr[3] = {charOneOr,charTwoOr,NULL};
    base *indBase = new indConnector(charArOr);
    indBase->execute();

    std::string cmdOne = "echo";
    char *charOne = const_cast<char*>(cmdOne.c_str());
    std::string argOne = "Hello World Two";
    char *charTwo = const_cast<char*>(argOne.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *orBase = new orConnector(indBase, charAr);
    orBase->execute();

    std::string cmdOneAnd = "echo";
    char *charOneAnd = const_cast<char*>(cmdOneAnd.c_str());
    std::string argOneAnd = "Hello World Three";
    char *charTwoAnd = const_cast<char*>(argOneAnd.c_str());
    char *charArAnd[3] = {charOneAnd,charTwoAnd,NULL};
    base *andBase = new andConnector(orBase, charArAnd);
    andBase->execute();

    EXPECT_EQ(andBase->isSuccessful(), false);
}

TEST(andConnectorTests, using_touch) {
   std::string cmdOneOr = "touch";
   char *charOneOr = const_cast<char*>(cmdOneOr.c_str());
   std::string argOneOr = "Hello.txt";
   char *charTwoOr = const_cast<char*>(argOneOr.c_str());
   char *charArOr[3] = {charOneOr,charTwoOr,NULL};
   base *indBase = new indConnector(charArOr);
   indBase->execute();

   std::string cmdOne = "touch";
   char *charOne = const_cast<char*>(cmdOne.c_str());
   std::string argOne = "Hello2.txt";
   char *charTwo = const_cast<char*>(argOne.c_str());
   char *charAr[3] = {charOne,charTwo,NULL};
   base *andBase = new andConnector(indBase, charAr);
   andBase->execute();

   EXPECT_EQ(andBase->isSuccessful(), true);
}

TEST(andConnectorTests, using_ls) {
   std::string cmdOneOr = "ls";
   char *charOneOr = const_cast<char*>(cmdOneOr.c_str());
   char *charArOr[2] = {charOneOr,NULL};
   base *indBase = new indConnector(charArOr);
   indBase->execute();

   std::string cmdOne = "ls";
   char *charOne = const_cast<char*>(cmdOne.c_str());
   char *charAr[2] = {charOne,NULL};
   base *andBase = new andConnector(indBase, charAr);
   andBase->execute();

   EXPECT_EQ(andBase->isSuccessful(), true);
}

#endif
