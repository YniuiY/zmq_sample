// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#ifndef MOCK_ZMQ_PUBLISHER_H
#define MOCK_ZMQ_PUBLISHER_H

#include <zmq.hpp>
#include <string>
#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace autodrive {
namespace buried {

class MockZmqPubliser {
 public:
  MockZmqPubliser() = default;
  ~MockZmqPubliser() = default;
  MockZmqPubliser(MockZmqPubliser const&) = delete;
  MockZmqPubliser(MockZmqPubliser&&) = delete;
  MockZmqPubliser& operator = (MockZmqPubliser const&) = delete;
  MockZmqPubliser& operator = (MockZmqPubliser&&) = delete;

  void Init() noexcept(false);
  void StartUp() noexcept(false);
  void Stop() noexcept(false);
  void Destory() noexcept(false);

  /// @brief append request info to self queue
  /// @param data_buf: data buffer
  /// @param nbyte: data size
  void AppendRequestInfo(void* data_buf, int const nbyte);

 private:
  void publish() noexcept(false);

  static constexpr std::uint32_t kMaxBufferSize{65535U};
  void* context_;
  void* publiser_;
  std::string request_topic_;
  std::string response_topic_;
  std::shared_ptr<std::array<std::uint8_t, kMaxBufferSize>> buffer_ptr_;
  bool is_running_;
  std::queue<std::shared_ptr<std::pair<int, std::array<std::uint8_t, kMaxBufferSize>>>> response_info_queue_;
  std::mutex queue_mutex_;
  std::condition_variable queue_cv_;
};

} // namespace buried
} // namespace autodrive

#endif