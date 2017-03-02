cmake_minimum_required(VERSION 3.1)

project(Dynace)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(include)

file(GLOB CLASS_SOURCES class/*.c)
list(REMOVE_ITEM CLASS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/class/FindFile.c
        ${CMAKE_CURRENT_SOURCE_DIR}/class/MimeBodyPart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/class/MultipartMime.c
        ${CMAKE_CURRENT_SOURCE_DIR}/class/Socket.c
        )
file(GLOB KERNEL_SOURCES kernel/*.c)
list(REMOVE_ITEM KERNEL_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/plan9.c
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/rtkernel.c
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/win32gm.c
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/mem.c
        )
message(STATUS ${KERNEL_SOURCES})

add_library(dynace SHARED
        ${CLASS_SOURCES}
        ${KERNEL_SOURCES}
        generics/generics.c)

add_executable(example
        examples/exam30/main.c
        #generics/generics.c
        )

target_link_libraries(example dynace)

file(GLOB DPP_SOURCES dpp/*.c)
add_executable(dpp
        ${DPP_SOURCES}
        )
target_link_libraries(dpp dynace)