#!/usr/bin/env bash

DOCKER_BUILD_IMAGE_NAME="advent-of-code-2022/builder"
CMAKE_BUILD_DIR_NAME="cmake-build-gcc-debug-docker"
SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
CMAKE_BUILD_DIR_PATH="${SCRIPT_DIR}/${CMAKE_BUILD_DIR_NAME}"

cd ${SCRIPT_DIR}

if ! docker image ls | grep ${DOCKER_BUILD_IMAGE_NAME} > /dev/null; then
  echo "Docker image ${DOCKER_BUILD_IMAGE_NAME} not found, building it locally."
  ./docker-builder/build.sh
fi

echo "Building project with docker."
mkdir -p ${CMAKE_BUILD_DIR_PATH}

docker run -v ${CMAKE_BUILD_DIR_PATH}:/build \
  -v ${SCRIPT_DIR}:/project \
  -t ${DOCKER_BUILD_IMAGE_NAME} \
  bash -c "cmake -DCMAKE_BUILD_TYPE=Debug -S ../project -B . && cmake --build . --target advent_of_code_2022_cpp -- -j 8"
