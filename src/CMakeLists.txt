cmake_minimum_required(VERSION 3.13)
project(test)

include_directories(Include)

set(SOURCES main.c Include/linkedlist.c Include/linkedlist.h)

add_executable(main.o ${SOURCES})