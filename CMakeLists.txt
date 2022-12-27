cmake_minimum_required(VERSION 3.22)
project(advent_of_code_2022_cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_Declare(asio
        GIT_REPOSITORY git@github.com:chriskohlhoff/asio.git
        GIT_TAG asio-1-24-0
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        )
FetchContent_MakeAvailable(googletest asio)

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
)

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
        src/cpp/ElfBuilderTests.cpp)

target_link_libraries(
        advent_of_code_2022_cpp_test PUBLIC
        ${EXTRA_LIBS}
        GTest::gtest_main
        asio
)

target_include_directories(
        advent_of_code_2022_cpp_test PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
)

include(GoogleTest)
gtest_discover_tests(advent_of_code_2022_cpp_test)
