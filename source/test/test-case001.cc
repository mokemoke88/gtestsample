/**
 * @file test/test.case001.cc
 */

#include "service/service.h"
#include <gtest/gtest.h>

TEST(MediaService, RangeTest){
  Service::UnitTestTargeSample();
}


namespace Service {

void testHandler(const std::string& message){
  std::cout << message << std::endl;
  sleep(3);
}

TEST(MessageQueue, construct){
  StringMessageQueue queue;
}

TEST(MessageQueue, nullhandler){
  StringMessageQueue queue;
  queue.RegisterHandler("nullptr", nullptr);
  sleep(1);
}

TEST(MessageQueue, nullhandlerWithMessage){
  StringMessageQueue queue;
  queue.RegisterHandler("nullptr", nullptr);
  queue.Post("hello");
  sleep(1);
  queue.Post("hello");
  sleep(1);
}

TEST(MessageQueue, lockinghandlerWithMessage){
  StringMessageQueue queue;
  queue.RegisterHandler("nullptr", nullptr);
  queue.RegisterHandler("nullptr", testHandler);
  queue.Post("hello");
  sleep(1);
  queue.Post("hello");
  sleep(1);
}

TEST(Sample, constructor){
  Sample s;
}

TEST(Sample, run){
  Sample s;
  s.Run();
  s.Run();
}

}
