cmake_minimum_required(VERSION 3.13)
project(test)

include_directories(Include)

add_executable(server server.c)
add_executable(client client.c)