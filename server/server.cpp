#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
//   const string endpoint = "tcp://*:5555";

//   zmqpp::context context;

//   zmqpp::socket_type type = zmqpp::socket_type::reply;
//   zmqpp::socket socket(context, type);

//   socket.bind(endpoint);

// #if 1
//   while (true) {
//     zmqpp::message message;
//     socket.receive(message);
//     string text;
//     message >> text;

//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     cout << "Recived Hello" << endl;
//     socket.send("World");
//   }
// #endif

const string endpoint = "ipc:///home/yangdi/zmq_comm.ipc";

  void * context = zmq_ctx_new();
  void * publisher = zmq_socket(context, ZMQ_PUB);
  zmq_bind(publisher, endpoint.c_str());


#if 1
  std::string data{"Hello Zmq"};
  char buffer[10] = "Hello Zmq";
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "pub data\n";
    for (auto b : buffer) {
      std::cout << "buffer: " << b << std::endl;
    }
    zmq_send(publisher, (void*)buffer, 10, 0);
  }
#endif
}