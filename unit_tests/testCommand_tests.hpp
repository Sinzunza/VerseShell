#ifndef __TESTCOMMAND_TESTS_HPP__
#define __TESTCOMMAND_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"


TEST(testCommandLiteralTests, noFlag) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string arg = "names.txt";
    char *charTwo = const_cast<char*>(arg.c_str());
    char *charAr[3] = {charOne,charTwo,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, eFlagFile) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-e";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, eFlagDir) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-e";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, fFlagFile) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-f";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testCommandLiteralTests, fFlagDir) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-f";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandLiteralTests, dFlagFile) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-d";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testCommandLiteralTests, dFlagDir) {
    std::string cmd = "test";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-d";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testSymbolicTests, noFlag) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "names.txt";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "]";
    char *charThree = const_cast<char*>(arg.c_str());
    char *charAr[4] = {charOne,charTwo,charThree,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testSymbolicTests, eFlagFile) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-e";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testSymbolicTests, eFlagDir) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-e";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testSymbolicTests, fFlagFile) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-f";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

TEST(testSymbolicTests, fFlagDir) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-f";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testSymbolicTests, dFlagFile) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-d";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "names.txt";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), false);
}

TEST(testSymbolicTests, dFlagDir) {
    std::string cmd = "[";
    char *charOne = const_cast<char*>(cmd.c_str());
    std::string flag = "-d";
    char *charTwo = const_cast<char*>(flag.c_str());
    std::string arg = "images";
    char *charThree = const_cast<char*>(arg.c_str());
    std::string argTwo = "]";
    char *charFour = const_cast<char*>(argTwo.c_str());
    char *charAr[5] = {charOne,charTwo,charThree,charFour,NULL};
    base *indBase = new indConnector(charAr);
    indBase->execute();
    EXPECT_EQ(indBase->isSuccessful(), true);
}

#endif
