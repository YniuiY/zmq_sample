// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#include "mock_zmq_subscriber.h"

#include <iostream>
#include <cassert>
#include <cstring>
#include <thread>

using std::cout;
using std::endl;

namespace autodrive {
namespace buried {

void MockZmqSubscriber::Init() noexcept(false){
  cout << "MockZmqSubscriber Init" << endl;
  request_info_callback_ = nullptr;
  context_ = zmq_ctx_new();
  cout << "context" << endl;
  subscirber_ = zmq_socket(context_, ZMQ_SUB);
  cout << "zmq_socket" << endl;
  int ret = zmq_connect(subscirber_, "tcp://127.0.0.1:10003");
  if (ret != 0) {
    cout << "connnect error\n";
    return;
  }

  topic_ = "HJ_uploadfile_request";
  is_running_ = false;
  buffer_ptr_ = std::make_shared<std::array<std::uint8_t, kMaxBufferSize>> ();

  if(zmq_setsockopt(subscirber_, ZMQ_SUBSCRIBE, topic_.c_str(), topic_.size()) != 0) {
    cout << "zmq_setsocket filter error" << endl;
    return;
  }

  cout << "MockZmqSubscriber Init Over" << endl;
}

void MockZmqSubscriber::Init(RequestInfoCallback req_info_cb) noexcept(false){
  cout << "MockZmqSubscriber Init" << endl;
  request_info_callback_ = nullptr;
  context_ = zmq_ctx_new();
  cout << "context" << endl;
  subscirber_ = zmq_socket(context_, ZMQ_SUB);
  cout << "zmq_socket" << endl;
  int ret = zmq_connect(subscirber_, "tcp://127.0.0.1:10003");
  if (ret != 0) {
    cout << "connnect error\n";
    return;
  }

  topic_ = "HJ_uploadfile_request";
  is_running_ = false;
  buffer_ptr_ = std::make_shared<std::array<std::uint8_t, kMaxBufferSize>> ();

  if(zmq_setsockopt(subscirber_, ZMQ_SUBSCRIBE, topic_.c_str(), topic_.size()) != 0) {
    cout << "zmq_setsocket filter error" << endl;
    return;
  }

  request_info_callback_ = req_info_cb;
  cout << "MockZmqSubscriber Init Over" << endl;
}

void MockZmqSubscriber::StartUp() noexcept(false) {
  cout << "MockZmqSubscriber StartUp" << endl;

  std::thread(&MockZmqSubscriber::subscribe, this).detach();
  is_running_ = true;

  cout << "MockZmqSubscriber StartUp Over" << endl;
}

void MockZmqSubscriber::Stop() noexcept(false) {
  cout << "MockZmqSubscriber Stop()" << endl;
  is_running_ = false;
  zmq_close(subscirber_);
  cout << "MockZmqSubscriber Stop Over()" << endl;
}

void MockZmqSubscriber::Destory() noexcept(false) {
  cout << "MockZmqSubscriber Destory()" << endl;
  zmq_ctx_destroy(context_);
  cout << "MockZmqSubscriber Destory Over()" << endl;
}

void MockZmqSubscriber::subscribe() noexcept(false) {
  cout << "MockZmqSubscriber subscribe()" << endl;

  int recv_size;
  while (is_running_) {
    memset(buffer_ptr_->data(), 0, buffer_ptr_->size());
    cout << "waitting for data" << endl;
    recv_size = zmq_recv(subscirber_, buffer_ptr_->data(), kMaxBufferSize, 0);
    cout << "recv_size: " << recv_size << endl;
    cout << "recv data: " << (char*)buffer_ptr_->data() << endl;
    /// @todo interactor data callback
    if (request_info_callback_ != nullptr) {
      request_info_callback_(buffer_ptr_->data(), recv_size);
    }
  }
  cout << "MockZmqSubscriber subscribe() Over" << endl;
}

} // namespace buried
} // namespace autodrive