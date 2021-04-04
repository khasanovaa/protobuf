#include "test.pb.h"

int main() {
  test::Person person;
  person.set_string_var("aliia");
  if (person.has_string_var()) {
    std::cout << "priv\n";
  }
  return 0;
}
