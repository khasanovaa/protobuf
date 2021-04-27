// This test calls all setters to make sure that none of them marks field as used and none of them contains
// __builtin_trap() after stripping.
#include "test.pb.h"

void call_setters() {
    test::Person p;
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

//    p.clear_oneof_int_var();
//    p.set_oneof_int_var(1);
//    p.clear_oneof_var();
}


int main() {
    call_setters();
    return 0;
}