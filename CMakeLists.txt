cmake_minimum_required(VERSION 3.15)

project(server)

find_package(nlohmann_json REQUIRED)

add_executable(server main.cpp)
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)

