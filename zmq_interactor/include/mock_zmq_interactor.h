// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#ifndef MOCK_ZMQ_INTERACTOR_H
#define MOCK_ZMQ_INTERACTOR_H

#include <zmq.hpp>
#include <string>
#include <memory>

namespace autodrive {
namespace buried {

class MockZmqSubscriber;
class MockZmqPubliser;
class MockZmqInteractor {
 public:
  MockZmqInteractor() = default;
  ~MockZmqInteractor() = default;
  MockZmqInteractor(MockZmqInteractor const&) = delete;
  MockZmqInteractor(MockZmqInteractor&&) = delete;
  MockZmqInteractor& operator = (MockZmqInteractor const&) = delete;
  MockZmqInteractor& operator = (MockZmqInteractor&&) = delete;

  void Init() noexcept(false);
  void StartUp() noexcept(false);
  void Stop() noexcept(false);
  void Destory() noexcept(false);

  /// @brief get request info
  /// @param data_buf: data buffer
  /// @param nbyte: data size
  static void GetRequestInfo(void *data_buf, int nbyte) noexcept(false);

 private:
  static std::shared_ptr<MockZmqSubscriber> subscriber_ptr_;
  static std::shared_ptr<MockZmqPubliser> publisher_ptr_;
};

} // namespace buried
} // namespace autodrive

#endif