#!/bin/bash

#annotate
protoc --cpp_out=annotate_accessor=true:. example.proto
c++ -std=c++11 example.cc example.pb.cc -o test_out_annotated `pkg-config --cflags --libs protobuf` -fdata-sections -ffunction-sections -g -Wl,--gc-sections
objdump -t test_out_annotated | c++filt | grep -oP '\S+(?=_DoNotStrip)' |  sed -e 's/::/./g' > accessed_fields.txt

#strip
protoc --cpp_out=unused_field_stripping=true,access_info_map="accessed_fields.txt":. example.proto
c++ -std=c++11 example.cc example.pb.cc -o test_out_stripped `pkg-config --cflags --libs protobuf`

#run without options
protoc --cpp_out=:. example.proto
c++ -std=c++11 example.cc example.pb.cc -o test_out `pkg-config --cflags --libs protobuf`

#infohas_oneof_var
echo -e "Stripped fields:"
cat accessed_fields.txt

echo -e "Stat without stripping:"
stat test_out
ninja check
echo -e "Stat with stripping:"
stat test_out_stripped

#cleaning
rm accessed_fields.txt test_out_annotated test_out test_out_stripped example.pb.h example.pb.cc
