// This test checks that oneof_var_case() marks all its fields as accessed
#include "test.pb.h"

int main() {
    test::Person p;
    p.oneof_var_case();
    return 0;
}
