#include "test.pb.h"

int dummy_string_fun() {
    test::Person p;
    p.has_string_var();
    return 8;
}
