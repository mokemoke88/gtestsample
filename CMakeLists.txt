# CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

PROJECT(GoogleTestSample VERSION 0.0.1 LANGUAGES C CXX)

ENABLE_TESTING()
ADD_SUBDIRECTORY(third-party/googletest)
include(GoogleTest)

ADD_SUBDIRECTORY(source/service)
ADD_SUBDIRECTORY(source/test)
