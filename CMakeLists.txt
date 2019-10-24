cmake_minimum_required(VERSION 3.15)

project (Interview-Training CXX)

add_compile_options(-Werror -Wextra -Wall -pedantic -std=c++11)

add_subdirectory(StringCompression)
add_subdirectory(LinkedList)
add_subdirectory(Stack-Queue)
