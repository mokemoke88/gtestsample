/**
 * @file service/messagequeue.cc 
 */

#include "service/messagequeue.hpp"
#include <string>

namespace Service {

template<typename T>
BasicMessageQueue<T>::BasicMessageQueue(): mtx_(), cond_(), queue_(), handlers_(), doterm_(false), thread_(nullptr)
{
  thread_ = std::make_shared<std::thread>([this]{
    messageLoop();
  });
}

template<typename T>
BasicMessageQueue<T>::~BasicMessageQueue() noexcept {
  doterm_ = true;
  cond_.notify_all();
  thread_->join();
}

template<typename T>
void BasicMessageQueue<T>::Post(T&& message){
  {
    std::lock_guard<std::recursive_mutex> lk(mtx_);
    queue_.emplace(std::forward<T>(message));
  }
  cond_.notify_all();
}

template<typename T>
void BasicMessageQueue<T>::RegisterHandler(const std::string key, NotifyHandler_t&& handler){
  {
    std::lock_guard<std::recursive_mutex> lk(mtx_);
    handlers_[key] = std::forward<NotifyHandler_t>(handler);
  }
}


template<typename T>
void BasicMessageQueue<T>::messageLoop(void){

  for(;;){
    std::unique_lock<std::recursive_mutex> lk(mtx_);
    cond_.wait(lk, [this]{ return !queue_.empty() || doterm_; });
    if(doterm_)
      break;
    processHandlers();
  }
}

template<typename T>
void BasicMessageQueue<T>::processHandlers(void) {
  T data = std::move( queue_.front() );
  queue_.pop();
  for(auto it = handlers_.cbegin(); it != handlers_.cend(); ++it){
    if( (*it).second ){
      (*it).second(data);
    }
  }
}

/**
 * Instancing BasicMessageQueue<std::string> 
 */
template class BasicMessageQueue<std::string>;
} // namespace
