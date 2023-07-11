// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#include "mock_zmq_publisher.h"

#include <iostream>
#include <cassert>
#include <cstring>
#include <thread>

using std::cout;
using std::endl;

namespace autodrive {
namespace buried {

void MockZmqPubliser::Init() noexcept(false) {
  cout << "MockZmqPubliser Init" << endl;
  context_ = zmq_ctx_new();
  cout << "new context" << endl;
  publiser_ = zmq_socket(context_, ZMQ_PUB);
  cout << "zmq_socket" << endl;
  int ret = zmq_bind(publiser_, "tcp://*:10005");
  if (ret != 0) {
    cout << "connnect error\n";
    return;
  } else {
    cout << "zmq bind success" << endl;
  }

  request_topic_ = "HJ_uploadfile_request";
  response_topic_ = "HJ_uploadfile_response";
  
  is_running_ = false;
  buffer_ptr_ = std::make_shared<std::array<std::uint8_t, kMaxBufferSize>> ();

  cout << "MockZmqPubliser Init Over" << endl;
}

void MockZmqPubliser::StartUp() noexcept(false) {
  cout << "MockZmqPubliser StartUp" << endl;

  std::thread(&MockZmqPubliser::publish, this).detach();
  is_running_ = true;

  cout << "MockZmqPubliser StartUp Over" << endl;
}

void MockZmqPubliser::Stop() noexcept(false) {
  cout << "MockZmqPubliser Stop()" << endl;
  is_running_ = false;
  zmq_close(publiser_);
  cout << "MockZmqPubliser Stop Over()" << endl;
}

void MockZmqPubliser::Destory() noexcept(false) {
  cout << "MockZmqPubliser Destory()" << endl;
  zmq_ctx_destroy(context_);
  cout << "MockZmqPubliser Destory Over()" << endl;
}

void MockZmqPubliser::AppendRequestInfo(void* data_buf, int const nbyte) noexcept(false) {
  cout << "MockZmqPubliser AppendRequestInfo()" << endl;

  std::shared_ptr<std::pair<int, std::array<std::uint8_t, kMaxBufferSize>>>
      data_and_size{std::make_shared<
          std::pair<int, std::array<std::uint8_t, kMaxBufferSize>>>()};

  data_and_size->first = nbyte - request_topic_.size();
  cout << "append buffer size: " << nbyte << endl;
  cout << "append msg: " << (char*)data_buf << endl;
  // remove topic
  memcpy(data_and_size->second.data(), data_buf + request_topic_.size(), nbyte - request_topic_.size());
  response_info_queue_.push(data_and_size);
  queue_cv_.notify_one();
  cout << "response info queue size: " <<response_info_queue_.size() << endl;

  cout << "MockZmqPubliser AppendRequestInfo() Over" << endl;
}

void MockZmqPubliser::publish() noexcept(false) {
  cout << "MockZmqPubliser subscribe()" << endl;

  std::array<uint8_t, 2048> send_buffer;
  int send_size;
  while (is_running_) {
    std::unique_lock<std::mutex> ul(queue_mutex_);
    while (response_info_queue_.empty()) {
      cout << "response info queue is empty, waitting..." << endl;
      queue_cv_.wait(ul);
    }
    auto data_and_size = response_info_queue_.front();
    memset(send_buffer.data(), 0, 2048);
    memcpy(send_buffer.data(), response_topic_.data(), response_topic_.size());
    memcpy(send_buffer.data() + response_topic_.size(), data_and_size->second.data(), data_and_size->first);
    send_size = zmq_send(publiser_, send_buffer.data(), data_and_size->first + response_topic_.size(), 0);
    if (send_size != (data_and_size->first + response_topic_.size())) {
      cout << "Send data error, real data size: " << data_and_size->first
           << ", error data size: " << send_size << endl;
      is_running_ = false;
    } else {
      response_info_queue_.pop();
      cout << "send msg: " << (char*)send_buffer.data() << endl;
      cout << "zmq send success, data size: " << send_size << endl;
    }
  }

  cout << "MockZmqPubliser subscribe() Over" << endl;
}

} // namespace buried
} // namespace autodrive