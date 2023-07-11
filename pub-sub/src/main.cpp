#include <iostream>

#include "zmq_publisher.h"
#include "zmq_subscriber.h"
#include "common.pb.h"
#include "frame.pb.h"
#include "topics.pb.h"
#include "Person.pb.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    int major{0};
    int minor{0};
    int patch{0};
    zmq_version(&major, &minor, &patch);
    std::cout << "ZMQ Version: " << major << "." << minor << "." << patch << std::endl;
    std::cout << "./zmq_comm pub, or ./zmq_comm sub\n";
    return 0;
  }
  std::string h0{"pub"};
  std::string h1{"sub"};
  if (h0.compare(argv[1]) == 0) {
    std::cout << "new publisher\n";
    ZmqPublisher publisher;
    publisher.Init("HJ");
    publisher.StartUp();

    for (int i = 0; i < 10; i++) {
      Person::person somebody;
      somebody.set_name("Tom");
      somebody.set_email("Tom@hongjingdrive.com");
      somebody.set_id(i);
      somebody.mutable_phones()->set_number("10086");
      somebody.mutable_phones()->set_type(Person::MOBILE);
      std::string person_data;
      somebody.SerializePartialToString(&person_data);
      int person_data_size = person_data.size();
      std::cout << "pub person data\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      publisher.Pub(person_data.data(), person_data_size);
    }
  } else if (h1.compare(argv[1]) == 0) {
    std::cout << "new subscriber\n";
    ZmqSubscriber subscriber;
    subscriber.Init("HJ"); // subscribe all 
    subscriber.Sub([](void const* msg, int msg_size) {
      Person::person somebody;
      somebody.ParsePartialFromArray(msg, msg_size);
      std::string phone_type = "Mobile Phone";
      if (somebody.phones().type() == Person::MOBILE) {
        phone_type = "Mobile Phone";
      } else if (somebody.phones().type() == Person::HOME) {
        phone_type = "Home Phone";
      }
      std::cout << "\n\nperson's info: "
                << "\nName: " << somebody.name()
                << "\nId: " << somebody.id()
                << "\nEmail: " << somebody.email()
                << "\nPhoneNumber: " << somebody.phones().number()
                << "\nPhoneType: " << phone_type << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    });
    subscriber.StartUp();

    std::string quiet;
    std::cin >> quiet; 
    while (quiet == "q" || quiet == "Q") {
      std::cout << "quiet progress\n";
      break;
    }
    subscriber.Stop();
  }

}