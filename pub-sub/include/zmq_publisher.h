#ifndef ZMQ_PUBLISHER_H_
#define ZMQ_PUBLISHER_H_

#include <zmq.hpp>
#include <memory>

class ZmqPublisher {
 public:
  ZmqPublisher();
  ~ZmqPublisher();
  void Init(std::string topic);
  void StartUp();
  void Stop();

  void Pub(void const* message, std::uint32_t msg_size);
 private:
  zmq::context_t context_ptr_;
  zmq::socket_t publisher_;
  zmq::socket_t sub_response_;
  std::string kIpcAddr = "ipc://comm.ipc";
  // static constexpr char* kTcpAddr = "tcp://*:8888";
  std::string kTcpAddr = "tcp://127.0.0.1:8888";
  std::string topic_;
};

#endif