#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
//   const string endpoint = "tcp://localhost:5555";

//   zmqpp::context context;

//   zmqpp::socket_type type = zmqpp::socket_type::request;
//   // zmqpp::socket_type type = zmqpp::socket_type::publish;
//   zmqpp::socket socket(context, type);

//   cout << "Connecting to hello world server..." << endl;
//   socket.connect(endpoint);

// #if 1
//   int request_nbr;
//   for (request_nbr = 0; request_nbr != 10; ++request_nbr) {
//     cout << "Sending Hello " << request_nbr << "..." <<endl;
//     zmqpp::message message;
//     message << "Hello";
//     socket.send(message);
//     string buffer;
//     socket.receive(buffer);

//     cout << " Recived " << buffer + " " << request_nbr << endl;
//   }
// #endif

const string addr = "ipc:///home/yangdi/zmq_comm.ipc";

  void* context = zmq_ctx_new();
  void* subscriber = zmq_socket(context, ZMQ_SUB);
  zmq_connect(subscriber, addr.c_str());
  std::string filter{""};

  zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

#if 1
  int request_nbr;
  for (request_nbr = 0; request_nbr != 10; ++request_nbr) {
    char buffer[1024];
    std::cout << "wait for recv\n";
    int size = zmq_recv(subscriber, (void*)buffer, 1024, 0);

    for (int i = 0; i < size; i++) {
      std::cout << "buffer: " << buffer[i] << std::endl;
    }
    memset(buffer, 0, 1024);
  }
#endif
}