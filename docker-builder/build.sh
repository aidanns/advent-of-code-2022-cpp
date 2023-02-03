#!/usr/bin/env bash

SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${SCRIPT_DIR}

docker build -t advent-of-code-2022/builder .