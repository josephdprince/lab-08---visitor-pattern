cmake_minimum_required(VERSION 3.17)

project(ProjectName)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main Add.hpp Div.hpp Mult.hpp Pow.hpp Sub.hpp Rand.hpp base.hpp op.hpp main.cpp iterator.cpp visitor.hpp)
ADD_EXECUTABLE(test unit_tests.cpp iterator.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
