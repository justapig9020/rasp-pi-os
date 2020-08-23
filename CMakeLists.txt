project(kernel8.img C ASM)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(tools /usr/local/bin/aarch64-none-elf/bin)
set(arm aarch64-none-elf)
set(CMAKE_C_COMPILER ${tools}/${arm}-gcc)
set(CMAKE_ASM_COMPILER ${tools}/${arm}-gcc)
set(CMAKE_C_LINKER_EXECUTABLE ${tools}/${arm}-ld)

include_directories(include)
add_subdirectory(src)

#add_custom_command(
#    TARGET claen
#    POST_BUILD
#    COMMAND rm
#    ${PROJECT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}
#    )
