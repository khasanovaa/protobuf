// This test (and all test{n}_getters_part{m}.cpp) checks that getters mark fields as used.
// Getters are split to several file to make sure that each of them annotates the corresponding field as accessed.
#include "test.pb.h"

void call_getters_part1(test::Person& p) {
    p.map_var_size();
    p.repeated_message_var_size();
    p.has_string_var();
    p.has_message_var();
    p.has_int_var();
    p.has_oneof_int_var();
}

int main() {
    test::Person p;
    call_getters_part1(p);
    return 0;
}
