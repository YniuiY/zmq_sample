#include "zmq_publisher.h"
#include <thread>
#include <iostream>

ZmqPublisher::ZmqPublisher() {}

ZmqPublisher::~ZmqPublisher() {
  Stop();
}

void ZmqPublisher::Init(std::string topic) {
  context_ptr_ = zmq::context_t();
  publisher_ = zmq::socket_t(context_ptr_, ZMQ_PUB);
  sub_response_ = zmq::socket_t(context_ptr_, ZMQ_DEALER);
  topic_ = topic;

  sub_response_.bind(kTcpAddr);
  if (sub_response_.handle() == nullptr) {
    std::cout << "sub response bind failed\n";
  } else {
    std::cout << "sub response bind over\n";
  }

  publisher_.bind(kIpcAddr);
  if (publisher_.handle() == nullptr) {
    std::cout << "publisher bind failed\n";
  } else {
    std::cout << "publisher bind over\n";
  }
}

void ZmqPublisher::StartUp() {
  // 等待pub请求，收到后才开始pub数据
  zmq::message_t pub_request;
  zmq::recv_result_t recv_result{sub_response_.recv(pub_request)};
  if (!recv_result.has_value()) {
    std::cout << "receve pub request error\n";
    return;
  } else {
    std::cout << "receve pub request: " << pub_request.to_string() << std::endl;
    std::cout << "Begin pub message\n\n";
  }
}

void ZmqPublisher::Stop() {
  std::cout << "Stop publish\n";
  publisher_.close();
  sub_response_.close();
  context_ptr_.close();
}

void ZmqPublisher::Pub(void const* message, std::uint32_t msg_size) {
  zmq::message_t topic_msg{topic_.data(), topic_.size()};
  zmq::send_result_t send_result{publisher_.send(topic_msg, zmq::send_flags::sndmore)};
  if (!send_result.has_value()) {
    std::cout << "send topic error\n";
  } else {
    zmq::message_t data_msg{message, msg_size};
    send_result = publisher_.send(data_msg, zmq::send_flags::none);
    if (!send_result.has_value()) {
      std::cout << "data msg send error\n";
    } else {
      std::cout << "data msg send success\n";
    }
  }
}