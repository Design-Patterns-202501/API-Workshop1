cmake_minimum_required(VERSION 3.15)

project(server)

find_package(nlohmann_json REQUIRED)

file(GLOB SOURCES
    utils/**/*.h
    booking/**/*.h 
    booking/**/*.cpp
    main.cpp
)

add_executable(server ${SOURCES})
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)

