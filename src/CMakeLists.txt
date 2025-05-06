cmake_minimum_required(VERSION 3.10)
project(FibonacciPalindromeLinkedlist)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    fibonacci.cpp
    palindrome.cpp
    linkedlist.cpp
    main_test.cpp
)

add_executable(FibonacciPalindromeLinkedlist ${SOURCES})

if(MSVC)
    message(STATUS "Building on Windows with MSVC")
else()
    if(UNIX)
        target_link_libraries(FibonacciPalindromeLinkedlist pthread)
    endif()
endif()

include(CTest)
add_test(NAME FibonacciPalindromeLinkedlistTest COMMAND FibonacciPalindromeLinkedlist)
