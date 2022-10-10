/**
 * @file service/sample.hpp
 */

#pragma once

#include <thread>
#include <mutex>
#include <memory>
namespace Service{

class Sample{
private:
  void messageLoop_(void);
public:
  void Run(void);
public:
  Sample();
  ~Sample() noexcept;
private:
  const int m_;
  std::mutex mtx_;
  std::shared_ptr<std::thread> th_;
};

} // namespace Service