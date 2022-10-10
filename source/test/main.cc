/**
 * @file test/main.cc
 *
 * test entry point
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

/**
 * エントリポイント
 */
int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
