project(kernel8.img)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_C_COMPILER /usr/local/bin/aarch64-none-elf/bin/aarch64-none-elf-gcc
)

include_directories(include)
add_subdirectory(src)
