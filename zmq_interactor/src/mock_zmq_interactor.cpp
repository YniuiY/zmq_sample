// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#include "mock_zmq_interactor.h"

#include <iostream>

#include "mock_zmq_subscriber.h"
#include "mock_zmq_publisher.h"

namespace autodrive {
namespace buried {

std::shared_ptr<MockZmqSubscriber> MockZmqInteractor::subscriber_ptr_{nullptr};
std::shared_ptr<MockZmqPubliser> MockZmqInteractor::publisher_ptr_{nullptr};

void MockZmqInteractor::Init() noexcept(false) {
  std::cout << "MockZmqInteractor::Init()" << std::endl;
  MockZmqInteractor::subscriber_ptr_ = std::make_shared<MockZmqSubscriber>();
  MockZmqInteractor::publisher_ptr_ = std::make_shared<MockZmqPubliser>();
  MockZmqInteractor::publisher_ptr_->Init();
  MockZmqInteractor::subscriber_ptr_->Init(MockZmqInteractor::GetRequestInfo);
}

void MockZmqInteractor::StartUp() noexcept(false) {
  std::cout << "MockZmqInteractor::StartUp()" << std::endl;
  MockZmqInteractor::publisher_ptr_->StartUp();
  MockZmqInteractor::subscriber_ptr_->StartUp();
}

void MockZmqInteractor::Stop() noexcept(false) {
   std::cout << "MockZmqInteractor::Stop()" << std::endl;
   MockZmqInteractor::subscriber_ptr_->Stop();
   MockZmqInteractor::publisher_ptr_->Stop();
}

void MockZmqInteractor::Destory() noexcept(false) {
  std::cout << "MockZmqInteractor::Destory()" << std::endl;
  MockZmqInteractor::subscriber_ptr_->Destory();
  MockZmqInteractor::publisher_ptr_->Destory();
}

void MockZmqInteractor::GetRequestInfo(void* data_buf, int nbyte) noexcept(false) {
  MockZmqInteractor::publisher_ptr_->AppendRequestInfo(data_buf, nbyte);
}

}
}