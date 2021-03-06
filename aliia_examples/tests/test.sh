#!/bin/bash

run_annotate_accessor() {
  protoc --cpp_out=annotate_accessor=true:. test.proto
  c++ -std=c++11 "$@" test.pb.cc -o test_out_annotated `pkg-config --cflags --libs protobuf` -fdata-sections -ffunction-sections -g -Wl,--gc-sections
  objdump -t test_out_annotated | c++filt | grep -oP '\S+(?=_DoNotStrip)' |  sed -e 's/::/./g' > accessed_fields.txt
}

run_strip() {
  protoc --cpp_out=unused_field_stripping=true,access_info_map="accessed_fields.txt":. test.proto
  c++ -std=c++11 "$@" test.pb.cc -o test_out_stripped `pkg-config --cflags --libs protobuf`
}

filenames=( $( ls test[0-9]*.cpp ) )
filenames[${#filenames[@]}]="test_last_1.cpp test_last_2.cpp"

expected_accessed_fields_numbers=( 0 0 10 6 7 4 2 2 4 10 2)
failed=false

for ((i = 0; i < ${#filenames[@]}; i++)); do
  filename=${filenames[i]}
  expected_accessed_filed_number=${expected_accessed_fields_numbers[i]}

  run_annotate_accessor $filename
  if [[ $(wc -l < accessed_fields.txt) != $expected_accessed_filed_number ]]; then
    echo "Test($i) failed: incorrect accessed fields number"
    cat accessed_fields.txt
    failed=true
  fi

  run_strip $filename
  if [[ $? != 0 ]]; then
    echo "Test($i) failed: stripped finished abnormal."
    failed=true
  fi
done

rm accessed_fields.txt test_out_annotated test_out_stripped test.pb.h test.pb.cc

if [[ $failed == false ]]; then
  echo "All tests passed!"
fi
