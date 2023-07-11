#include "zmq_subscriber.h"
#include <iostream>

ZmqSubscriber::ZmqSubscriber() {}

ZmqSubscriber::~ZmqSubscriber() {
  Stop();
}

void ZmqSubscriber::Init(std::string topic) {
  topic_ = topic;
  context_ptr_ = zmq::context_t();
  buffer_ = std::make_shared<std::array<char, kMaxBufferSize>>();
  subscriber_ = zmq::socket_t(context_ptr_, ZMQ_SUB);
  pub_request_ = zmq::socket_t(context_ptr_, ZMQ_DEALER);

  subscriber_.connect(kIpcAddr);
  if (subscriber_.handle() == nullptr) {
    std::cout << "zmq connect error\n";
  } else {
    std::cout << "zmq connect success\n";
  }

  pub_request_.connect(kTcpAddr);
  if (pub_request_.handle() == nullptr) {
    std::cout << "pub request connect error\n";
  } else {
    std::cout << "pub request connect success\n";
  }

  subscriber_.setsockopt(ZMQ_SUBSCRIBE, topic_.data(), topic_.size());
}

void ZmqSubscriber::Sub(SubCallback const& callback) {
  callback_ = callback;
}

void ZmqSubscriber::StartUp() {
  start_ = true;

  call_callback_ = std::make_shared<std::thread>([this](){
    while (start_) {
      {
        while (start_ && message_queue_.empty()) {
          std::cout << "message queue is empty\n";
          std::unique_lock<std::mutex> ul(mutex_);
          msg_cv_.wait(ul);
        }
        if (!start_) {
          break;
        }
        auto msg = message_queue_.front();
        message_queue_.pop();
        callback_(msg.message_.data(), msg.data_size_);
      }
    }
  });

  recv_msg_ = std::make_shared<std::thread>([this]() {
    // 发送pub请求
    std::string pub_req_str{"sub endpoint ready, request pub message"};
    zmq::message_t pub_req_msg{pub_req_str.data(), pub_req_str.size()};
    zmq::send_result_t send_result{pub_request_.send(pub_req_msg, zmq::send_flags::none)};
    if (!send_result.has_value()) {
      std::cout << "zmq send pub request error\n";
      start_ = false;
      msg_cv_.notify_all();
    } else {
      std::cout << "pub request send success\n";
    }

    while (start_) {
      MessageData msg_data;
      zmq::message_t topic_msg;
      std::cout << "wait recv topic msg\n";
      zmq::recv_result_t recv_result{subscriber_.recv(topic_msg)};
      if (!recv_result.has_value()) {
        std::cout << "topic recv error\n";
      } else {
        std::cout << "recv topic msg: " << topic_msg.to_string() << std::endl;
      }

      zmq::message_t data_msg;
      recv_result = subscriber_.recv(data_msg);
      if (!recv_result.has_value()) {
        std::cout << "data msg recv error\n";
      } else {
        std::cout << "recv data msg success" << std::endl;
      }

      // msg_data.buffer_ = buffer;
      msg_data.message_ = data_msg.to_string();
      msg_data.data_size_ = data_msg.size();
      {
        std::unique_lock<std::mutex> ul(mutex_);
        message_queue_.push(std::move(msg_data));
        msg_cv_.notify_one();
      };
    }
  });

}

void ZmqSubscriber::Stop() {
  if (!start_) return;
  start_ = false;
  msg_cv_.notify_all();
  subscriber_.close();
  pub_request_.close();
  context_ptr_.close();
  if (recv_msg_ && recv_msg_->joinable()) {
    recv_msg_->join();
  }

  if (call_callback_ && call_callback_->joinable()) {
    call_callback_->join();
  }
}