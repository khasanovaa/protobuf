#!/bin/bash
COLOR='\033[0;33m'
NC='\033[0m'

#annotate
protoc --cpp_out=annotate_accessor=true:. test.proto
c++ -std=c++11 -Wno-return-type test.cc test.pb.cc -o test_out_annotated `pkg-config --cflags --libs protobuf` -fdata-sections -ffunction-sections -g -Wl,--gc-sections
objdump -t test_out_annotated | c++filt | grep -oP '\S+(?=_DoNotStrip)' |  sed -e 's/::/./g' > accessed_fields.txt

#strip
protoc --cpp_out=unused_field_stripping=true,access_info_map="accessed_fields.txt":. test.proto
c++ -std=c++11 -Wno-return-type test.cc test.pb.cc -o test_out_stripped `pkg-config --cflags --libs protobuf`

#run without options
protoc --cpp_out=:. test.proto
c++ -std=c++11 -Wno-return-type test.cc test.pb.cc -o test_out `pkg-config --cflags --libs protobuf`

#info
echo -e ${COLOR}"Stripped fields:"${NC}
cat accessed_fields.txt

echo -e ${COLOR}"Stat without stripping:"${NC}
stat test_out

echo -e ${COLOR}"Stat with stripping:"${NC}
stat test_out_stripped

#cleaning
rm accessed_fields.txt test_out_annotated test_out test_out_stripped test.pb.h test.pb.cc
