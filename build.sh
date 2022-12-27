#!/usr/bin/env bash

SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${SCRIPT_DIR}

cmake -S . -B build
cmake --build build

