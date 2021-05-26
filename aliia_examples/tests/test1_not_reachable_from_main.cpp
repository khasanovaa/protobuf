// This test contains all fields methods, but they are not reachable from main. Checks that non of these methods was
// deleted to avoid compilation errors.
#include "test.pb.h"

void call_setters(test::Person p) {
    std::string str("priv");

    p.clear_map_var();

    p.clear_repeated_message_var();
    auto nested = p.add_repeated_message_var();

    p.clear_string_var();
    p.set_string_var(str);
    p.set_string_var(std::move(str));
    str = "priv";
    p.set_string_var(str.c_str());
    p.set_string_var(str.c_str(), 1);
    p.set_allocated_string_var(&str);

    p.clear_message_var();
    p.set_allocated_message_var(nested);

    p.clear_int_var();
    p.set_int_var(1);

    p.clear_enum_var();
    p.set_enum_var(::test::SimpleEnum::BAR_VALUE);

    p.clear_oneof_int_var();
    p.set_oneof_int_var(1);
    p.clear_oneof_var();
}

void call_getters(test::Person& p) {
    p.map_var_size();
    p.map_var();
    p.mutable_map_var();

    p.repeated_message_var_size();
    p.mutable_repeated_message_var(10);
    p.mutable_repeated_message_var();
    p.repeated_message_var(10);
    p.repeated_message_var();

    p.has_string_var();
    p.string_var();
    p.mutable_string_var();
    p.release_string_var();

    p.has_message_var();
    p.message_var();
    p.release_message_var();
    p.mutable_message_var();

    p.has_int_var();
    p.int_var();

    p.enum_var();

    p.has_oneof_int_var();
    p.oneof_int_var();
}

int main() {
    return 0;
}