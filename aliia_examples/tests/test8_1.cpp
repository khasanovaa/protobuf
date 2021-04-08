// This test checks that all accessed fields are annotated with two modules for compilation.
#include "test.pb.h"
#include "iostream"

int dummy_string_fun();

int main() {
    test::Person p;
    p.has_int_var();
    std::cout << dummy_string_fun();
    return 0;
}
