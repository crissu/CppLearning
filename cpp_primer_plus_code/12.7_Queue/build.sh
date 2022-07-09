#!/bin/bash

init() {
  echo "do init process"
  mkdir -p build
}

build() {
  echo "do build process"
  cd build
  cmake ..
  make
}

source /etc/profile
init && build