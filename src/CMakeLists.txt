cmake_minimum_required(VERSION 3.10)
project(FibonacciPalindromeLinkedlist)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)

set(SOURCES
    fibonacci.cpp
    palindrome.cpp
    linkedlist.cpp
    main_test.cpp
)

add_executable(FibonacciPalindromeLinkedlist ${SOURCES})

target_include_directories(FibonacciPalindromeLinkedlist PRIVATE ${catch2_SOURCE_DIR}/single_include)

target_link_libraries(FibonacciPalindromeLinkedlist PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(FibonacciPalindromeLinkedlist)
