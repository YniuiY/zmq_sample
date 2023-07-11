#ifndef ZMQ_SUBSCRIBER_H_
#define ZMQ_SUBSCRIBER_H_

#include <zmq.hpp>
#include <thread>
#include <functional>
#include <memory>
#include <queue>
#include <condition_variable>

class ZmqSubscriber {
 public:
  using SubCallback = std::function<void(void const* msg, std::uint32_t msg_size)>;

  ZmqSubscriber();
  ~ZmqSubscriber();
  void Init(std::string topic);
  void StartUp();
  void Stop();
  void Sub(SubCallback const& callback);

 private:
  static constexpr int kMaxBufferSize = 65535;
  struct MessageData {
    std::array<char, kMaxBufferSize> buffer_;
    std::string message_;
    std::uint32_t data_size_;
  };
  zmq::context_t context_ptr_;
  zmq::socket_t subscriber_;
  zmq::socket_t pub_request_;
  std::shared_ptr<std::thread> recv_msg_;
  std::shared_ptr<std::thread> call_callback_;
  std::string topic_;
  SubCallback callback_;
  std::queue<MessageData> message_queue_;
  bool start_;
  std::shared_ptr<std::array<char, kMaxBufferSize>> buffer_;
  std::mutex mutex_;
  std::condition_variable msg_cv_;
  std::string kIpcAddr = "ipc://comm.ipc";
  std::string kTcpAddr = "tcp://127.0.0.1:8888";
};

#endif