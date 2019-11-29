#ifndef __ANDCONNECTOR_TESTS_HPP__
#define __ANDCONNECTOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "../src/indConnector.hpp"
#include "../src/orConnector.hpp"
#include "../src/andConnector.hpp"


TEST(andConnectorTests, using_echo_succeeded) {
    base *indBase = new indConnector("echo Hello");
    indBase->execute();

    base *andBase = new andConnector(indBase, "echo Hello World Two");
    andBase->execute();

    EXPECT_EQ(andBase->isSuccessful(), true);
}

TEST(andConnectorTests, using_echo_not_succeeded) {
    base *indBase2 = new indConnector("fdgjk Hello World");
    indBase2->execute();

    base *andBase2 = new andConnector(indBase2, "echo Hello World Two");
    andBase2->execute();

    EXPECT_EQ(andBase2->isSuccessful(),false);
}


TEST(andConnectorTests, using_echo_succeeded_allConnectors) {
    base *indBase = new indConnector("echo Hello World");
    indBase->execute();

    base *orBase = new orConnector(indBase, "echo Hello World Two");
    orBase->execute();

    base *andBase = new andConnector(orBase, "echo Hello World Three");
    andBase->execute();

    EXPECT_EQ(andBase->isSuccessful(), true);
}

TEST(andConnectorTests, using_ls) {
   base *indBase = new indConnector("ls");
   indBase->execute();

   base *andBase = new andConnector(indBase, "ls");
   andBase->execute();

   EXPECT_EQ(andBase->isSuccessful(), true);
}

#endif
