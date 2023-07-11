// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16
#ifndef MOCK_ZMQ_SUBSCRIBER_H
#define MOCK_ZMQ_SUBSCRIBER_H

#include <zmq.hpp>
#include <string>
#include <memory>
#include <queue>
#include <functional>

namespace autodrive {
namespace buried {

class MockZmqSubscriber {
 public:
  using RequestInfoCallback = std::function<void(void*, int)>;

  MockZmqSubscriber() = default;
  ~MockZmqSubscriber() = default;
  MockZmqSubscriber(MockZmqSubscriber const&) = delete;
  MockZmqSubscriber(MockZmqSubscriber&&) = delete;
  MockZmqSubscriber& operator = (MockZmqSubscriber const&) = delete;
  MockZmqSubscriber& operator = (MockZmqSubscriber&&) = delete;

  void Init() noexcept(false);
  void Init(RequestInfoCallback) noexcept(false);
  void StartUp() noexcept(false);
  void Stop() noexcept(false);
  void Destory() noexcept(false);

 private:
  void subscribe() noexcept(false);
  
  static constexpr std::uint32_t kMaxBufferSize{65535U};

  void* context_;
  void* subscirber_;
  std::string topic_;
  std::shared_ptr<std::array<std::uint8_t, kMaxBufferSize>> buffer_ptr_;
  bool is_running_;
  /// @brief request info queue, pair<info size, info buffer>
  std::queue<std::pair<int, std::array<std::uint8_t, kMaxBufferSize>>> request_info_queue_;
  RequestInfoCallback request_info_callback_;
};

} // namespace buried
} // namespace autodrive

#endif