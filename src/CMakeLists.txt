file(GLOB srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
add_executable(kernel8.elf ${srcs})
