// This test checks that AccessAllFields() marks all message fields as accessed
#include "test.pb.h"

int main() {
    test::Person p;
    p.AccessAllFields();
    return 0;
}
