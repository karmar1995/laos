#!/bin/bash

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

rm -rf ./install
rm -rf ./build
mkdir ./build
cd ./build
cmake ..
cmake --build .
cmake --install .
