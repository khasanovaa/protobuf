// Running this example with annotate_accessor option marks only string_var filed as used.
// To compare the size of the final binary file with and without unused fields stripping run ./check.sh
#include "example.pb.h"

int main() {
    test::Person person;
    person.set_string_var("aliia");
    if (person.has_string_var()) {
        std::cout << "priv\n";
    }
    return 0;
}