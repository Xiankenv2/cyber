cmake_minimum_required(VERSION 3.16)
project(sentrybox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sentryctl
    src/main.c
    src/plugin_discovery.c
)

target_include_directories(sentryctl PRIVATE include)
