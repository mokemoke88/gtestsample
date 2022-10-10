/**
 * @file service.sample.cc
 */

#include "service/sample.hpp"

#include <memory>
#include <functional>

namespace Service{
Sample::Sample(): m_(1), mtx_(), th_(nullptr)
{
}

Sample::~Sample(){
  if(th_){
    th_->join();
  }
  th_.reset();
}

void Sample::Run(void){
  if(th_) return;
  th_ = std::make_shared<std::thread>(std::bind(&Sample::messageLoop_, this));
}

void Sample::messageLoop_(void){

}
}