#cmake_minimum_required(VERSION 3.1)

#project(Dynace)
#set(CMAKE_VERBOSE_MAKEFILE ON)
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
file(GLOB THREAD_SOURCES threads/*.c)
list(REMOVE_ITEM THREAD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/threads/timer.c )
if(WIN32)
    list(REMOVE_ITEM THREAD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/threads/unixtime.c )
else()
    list(REMOVE_ITEM THREAD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/threads/nttimer.c)
endif()

add_library(dynace STATIC
        ${CLASS_SOURCES}
        ${KERNEL_SOURCES}
        ${THREAD_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/class/Socket.c
        )

file(GLOB DPP_SOURCES dpp/*.c)
add_executable(dpp
        ${DPP_SOURCES}
        ${CLASS_SOURCES}
        ${KERNEL_SOURCES}
        )
target_link_libraries(dpp dynace)

add_executable(example
        examples/exam30/main.c
        #generics/generics.c
        )

target_link_libraries(example dynace)

