cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDDARD 23)
set(CMAKE_CXX_STANDDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(server)

find_package(nlohmann_json REQUIRED)
find_package(mongocxx REQUIRED)

file(GLOB SOURCES
    utils/**/*.h
    booking/**/*.h 
    booking/**/*.cpp
    lib/**/*.h
    lib/**/*.cpp
    schemas/**/*.h
    schemas/**/*.cpp
    main.cpp
)
add_executable(server ${SOURCES})
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(server PRIVATE mongo::mongocxx_static)

