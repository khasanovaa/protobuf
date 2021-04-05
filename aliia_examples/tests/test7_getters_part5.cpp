// See the *_getters_part1.cpp for the description
#include "test.pb.h"

void call_getters_part5(test::Person& p) {
    p.release_message_var();
    p.mutable_repeated_message_var(10);
}

int main() {
    test::Person p;
    call_getters_part5(p);
    return 0;
}
