#!/bin/bash

mkdir -p build &&
cd build &&
cmake -DCMAKE_BUILD_TYPE=Debug ../src &&
make &&
./qsim_test/QSimTest