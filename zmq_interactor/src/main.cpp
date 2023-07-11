// Copyright(c) 2018-2023 Hongjing
// All rights reserved.
//
// Author: Yang Di
// Update: 2023-03-16

#include "mock_zmq_interactor.h"
#include "mock_zmq_subscriber.h"

#include <iostream>
#include <thread>

using namespace autodrive;
using namespace buried;

int main() {
  std::shared_ptr<MockZmqInteractor> interactor{std::make_shared<MockZmqInteractor>()};
  std::thread([interactor]() -> void{
    int over;
    // cin 0 to exit process
    std::cin >> over;
    if (over == 0) {
      interactor->Stop();
      interactor->Destory();
    }
  }).detach();

  interactor->Init();
  interactor->StartUp();

  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

}