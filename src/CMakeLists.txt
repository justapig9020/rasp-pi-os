set(CMAKE_C_FLAGS "-Wall -nostdlib -nostartfiles -ffreestanding -mgeneral-regs-only")
message(CURRENT: ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXE_LINKER_FLAGS -T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld)

file(GLOB srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.[cS])
message(${srcs})
add_executable(kernel8.elf ${srcs})
message(RUNTIME OUTPUT: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(PROJECT SOURCE DIR: ${PROJECT_SOURCE_DIR})
add_custom_command(
    TARGET kernel8.elf
    POST_BUILD
    COMMAND ${tools}/${arm}-objcopy
    ARGS -Obinary ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/kernel8.elf ${PROJECT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}
    )
