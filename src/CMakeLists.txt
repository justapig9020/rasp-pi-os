set(CMAKE_C_FLAGS "-Wall -nostdlib -nostartfiles -ffreestanding -mgeneral-regs-only -MMD")
set(CMAKE_ASM_FLAGS "-MMD")
message(CURRENT: ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXE_LINKER_FLAGS "-T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld -Wl,--build-id=none")

# file(GLOB srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.[cS])
# message(${srcs})
# add_executable(kernel8.elf ${srcs})
add_executable(kernel8.elf main.c boot.S)
message(RUNTIME OUTPUT: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(PROJECT SOURCE DIR: ${PROJECT_SOURCE_DIR})
add_custom_target(
    ${CMAKE_PROJECT_NAME}
    ALL
    ${tools}/${arm}-objcopy 
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/kernel8.elf -O binary ${PROJECT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}
    DEPENDS kernel8.elf
    )
