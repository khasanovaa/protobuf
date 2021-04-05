// See the *_getters_part1.cpp for the description
#include "test.pb.h"

void call_getters_part3(test::Person& p) {
    p.mutable_map_var();
    p.mutable_string_var();
    p.mutable_repeated_message_var();
    p.mutable_message_var();
}

int main() {
    test::Person p;
    call_getters_part3(p);
    return 0;
}
