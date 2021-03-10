#include "test.pb.h"

int main() {
  test::Person person;
  person.set_name("aliia");
  if (person.has_name()) {
      person.set_id(1);
  }
  std::cout << person.id() << '\n'; 
  return 0;
}
