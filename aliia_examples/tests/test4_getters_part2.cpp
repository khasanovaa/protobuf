// See the *_getters_part1.cpp for the description
#include "test.pb.h"

void call_getters_part2(test::Person& p) {
    p.map_var();
    p.string_var();
    p.repeated_message_var();
    p.enum_var();
    p.oneof_int_var();
    p.int_var();
    p.message_var();
}

int main() {
    test::Person p;
    call_getters_part2(p);
    return 0;
}
