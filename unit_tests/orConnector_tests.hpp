#ifndef __ORCONNECTOR_TESTS_HPP__
#define __ORCONNECTOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"
#include "../src/orConnector.hpp"
#include "../src/andConnector.hpp"


TEST(orConnectorTests, using_echo_succeeded) {
    base *indBase = new indConnector("echo Hello World");
    indBase->execute();

    base *orBase = new orConnector(indBase, "echo Hello World Two");
    orBase->execute();

    EXPECT_EQ(orBase->isSuccessful(), true);
}

TEST(orConnectorTests, using_echo_not_succeeded) {
    base *indBase2 = new indConnector("fdhk Hello World");
    indBase2->execute();
    
    base *orBase2 = new orConnector(indBase2, "echo Hello World Two");
    orBase2->execute();

    EXPECT_EQ(orBase2->isSuccessful(), true);
}

TEST(orConnectorTests, using_echo_succeeded_allConnectors) {
    base *indBase = new indConnector("echo Hello World");
    indBase->execute();

    base *andBase = new andConnector(indBase, "echo Hello World Two");
    andBase->execute(); 

    base *orBase = new orConnector(andBase, "echo Hello World Three");
    orBase->execute();

    EXPECT_EQ(orBase->isSuccessful(), true);//since didn't fail. it is considered successful, even though it didn't run. logical operator
}

TEST(orConnectorTests, using_ls) {
   base *indBase = new indConnector("lt");
   indBase->execute();

   base *orBase = new orConnector(indBase, "ls");
   orBase->execute();

   EXPECT_EQ(orBase->isSuccessful(), true);
}

#endif
