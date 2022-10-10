/**
 * @file service/messagequeue.hpp
 * 
 */

#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <string>
#include <memory>
#include <thread>

namespace Service{


template<typename T>
class BasicMessageQueue{
public:
  using NotifyHandler_t = std::function<void (const T&)>;

public:
  void Post(T&& message);
  void RegisterHandler(const std::string /*key*/, NotifyHandler_t&& /*handler*/);

private:
  void messageLoop(void);
  void processHandlers(void);
public:
  BasicMessageQueue();
  BasicMessageQueue(const BasicMessageQueue<T>&) = delete;
  BasicMessageQueue<T>& operator = (const BasicMessageQueue<T>&) = delete;
  ~BasicMessageQueue() noexcept;

private:
  std::recursive_mutex mtx_;
  std::condition_variable_any cond_;
  std::queue<T> queue_;
  std::unordered_map<std::string, NotifyHandler_t> handlers_;
  bool doterm_;
  std::shared_ptr<std::thread> thread_;
};

using StringMessageQueue = BasicMessageQueue<std::string>;

} // namesapce service
