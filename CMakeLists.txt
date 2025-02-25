cmake_minimum_required(VERSION 3.30)
SET(EXECUTABLE_OUTPUT_PATH bin)


project(bin)
file(GLOB bin_src "src/*.c")
add_executable(bin ${bin_src})
