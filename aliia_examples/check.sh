#!/bin/bash

protoc --cpp_out=annotate_accessor=true:. test.proto
c++ -std=c++11 test.cc test.pb.cc -o test_out `pkg-config --cflags --libs protobuf` -fdata-sections -ffunction-sections -g -Wl,--gc-sections
objdump -t test_out | c++filt | grep -o "\S*DoNotStrip"
