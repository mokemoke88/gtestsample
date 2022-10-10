#
# @file test/CMakeLists.txt
#

# unit test source code
FILE(GLOB SOURCES *.cc)
# unit test target source code
SET(TEST_TARGETS ../service/unit.target.cc ../service/messagequeue.cc ../service/sample.cc)

ADD_EXECUTABLE(service.test)
TARGET_SOURCES(service.test
PRIVATE
  ${SOURCES}
  ${TEST_TARGETS}
)
TARGET_LINK_LIBRARIES(service.test
PRIVATE
  gtest
  gmock
  gcov
)
TARGET_INCLUDE_DIRECTORIES(service.test
PRIVATE
  ../../include
)
# どっちが正解?
#TARGET_COMPILE_FEATURES(service.test PUBLIC cxx_std_14)
SET_PROPERTY(TARGET service.test PROPERTY CXX_STANDARD 14)
TARGET_COMPILE_OPTIONS(service.test
PRIVATE
  -O0
  -Wall
  -fno-exceptions # 例外処理を行わない. カバレッジレポートに影響
  --coverage
)

INCLUDE(GoogleTest)

# cmake test に テストケースを認識させる.
gtest_discover_tests(service.test)
