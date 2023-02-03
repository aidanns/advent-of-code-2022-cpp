FROM ubuntu:22.04
COPY ./cmake-build-gcc-debug-docker/advent_of_code_2022_cpp /advent_of_code_2022_cpp
CMD ["/advent_of_code_2022_cpp"]