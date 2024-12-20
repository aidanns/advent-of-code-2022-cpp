cmake_minimum_required(VERSION 3.22)
project(advent_of_code_2022_cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Statically link libraries so we can run in a Docker scratch container.
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_Declare(asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-24-0
        CONFIGURE_COMMAND ""
        BUILD_COMMAND "")
FetchContent_Declare(
        nanobench
        GIT_REPOSITORY https://github.com/martinus/nanobench.git
        GIT_TAG v4.3.9
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(asio googletest nanobench)

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
find_package(Threads)
target_link_libraries(asio INTERFACE Threads::Threads)

enable_testing()

configure_file(src/cmake/AdventOfCodeConfig.h.in src/cpp/generated/AdventOfCodeConfig.h)

add_executable(
        advent_of_code_2022_cpp
        src/cpp/main.cpp
        src/cpp/DayOne.h
        src/cpp/DayOne.cpp
        src/cpp/DayOneParser.cpp
        src/cpp/DayOneParser.h
        src/cpp/Food.cpp
        src/cpp/Food.h
        src/cpp/ElfBuilder.cpp
        src/cpp/ElfBuilder.h
        src/cpp/Elf.cpp
        src/cpp/Elf.h
        src/cpp/DayTwo.cpp
        src/cpp/DayTwo.h
        src/cpp/DayTwoParser.cpp
        src/cpp/DayTwoParser.h
        src/cpp/RockPaperScissors.cpp
        src/cpp/RockPaperScissors.h
        src/cpp/InputFileReader.cpp
        src/cpp/InputFileReader.h
        src/cpp/DayThree.cpp
        src/cpp/DayThree.h
        src/cpp/Item.h
        src/cpp/Item.cpp
        src/cpp/Rucksack.cpp
        src/cpp/Rucksack.h
        src/cpp/DayThreeParser.cpp
        src/cpp/DayThreeParser.h)

target_link_libraries(
        advent_of_code_2022_cpp PUBLIC
        ${EXTRA_LIBS}
        GTest::gtest_main
        asio
)

target_include_directories(
        advent_of_code_2022_cpp PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
)

add_executable(
        advent_of_code_2022_cpp_test
        src/cpp/DayOne.h
        src/cpp/DayOne.cpp
        src/cpp/DayOneTests.cpp
        src/cpp/DayOneParser.cpp
        src/cpp/DayOneParser.h
        src/cpp/DayOneParserTests.cpp
        src/cpp/Food.cpp
        src/cpp/Food.h
        src/cpp/Elf.cpp
        src/cpp/Elf.h
        src/cpp/ElfTests.cpp
        src/cpp/ElfBuilder.cpp
        src/cpp/ElfBuilder.h
        src/cpp/ElfBuilderTests.cpp
        src/cpp/DayTwo.cpp
        src/cpp/DayTwo.h
        src/cpp/DayTwoTests.cpp
        src/cpp/DayTwoParser.cpp
        src/cpp/DayTwoParser.h
        src/cpp/RockPaperScissors.cpp
        src/cpp/RockPaperScissors.h
        src/cpp/RockPaperScissorsTests.cpp
        src/cpp/DayTwoParserTests.cpp
        src/cpp/InputFileReader.cpp
        src/cpp/InputFileReader.h
        src/cpp/DayThree.cpp
        src/cpp/DayThree.h
        src/cpp/DayThreeTests.cpp
        src/cpp/Item.h
        src/cpp/Item.cpp
        src/cpp/ItemTests.cpp
        src/cpp/Rucksack.cpp
        src/cpp/Rucksack.h
        src/cpp/RucksackTests.cpp
        src/cpp/DayThreeParser.cpp
        src/cpp/DayThreeParser.h
        src/cpp/DayThreeParserTests.cpp)

target_link_libraries(
        advent_of_code_2022_cpp_test PUBLIC
        ${EXTRA_LIBS}
        asio
        GTest::gtest_main
        nanobench
)

target_include_directories(
        advent_of_code_2022_cpp_test PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
)

include(GoogleTest)
gtest_discover_tests(advent_of_code_2022_cpp_test)

# Add a command that allows the input file to be copied to the build directory.
add_custom_command(
        OUTPUT input_day_one.txt
        COMMAND mkdir -p var/data
        COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/src/data/input_day_one.txt ./var/data/input_day_one.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/data/input_day_one.txt
        VERBATIM)
# Add a target that runs that command.
add_custom_target(input_day_one
        DEPENDS input_day_one.txt)
# Make the build target depend on that target.
add_dependencies(advent_of_code_2022_cpp input_day_one)

add_custom_command(
        OUTPUT Dockerfile
        COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Dockerfile ./Dockerfile
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Dockerfile
        VERBATIM)
add_custom_target(dockerfile DEPENDS Dockerfile)
add_dependencies(advent_of_code_2022_cpp dockerfile)

add_custom_command(
        OUTPUT docker-compose.yml
        COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/docker-compose.yml ./docker-compose.yml
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/docker-compose.yml
        VERBATIM)
add_custom_target(docker_compose_yml DEPENDS docker-compose.yml)
add_dependencies(advent_of_code_2022_cpp docker_compose_yml)