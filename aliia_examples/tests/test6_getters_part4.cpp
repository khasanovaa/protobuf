// See the *_getters_part1.cpp for the description
#include "test.pb.h"

void call_getters_part4(test::Person& p) {
    p.repeated_message_var(10);
    p.release_string_var();
}

int main() {
    test::Person p;
    call_getters_part4(p);
    return 0;
}
