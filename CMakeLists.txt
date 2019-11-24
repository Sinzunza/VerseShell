CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unit-test
	unit_tests/unit_tests.cpp 
)

TARGET_LINK_LIBRARIES(unit-test gtest)

TARGET_COMPILE_DEFINITIONS(unit-test PRIVATE gtest_disable_pthreads=ON)
