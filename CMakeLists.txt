cmake_minimum_required (VERSION 3.26)

project (Calculator VERSION 1.1 LANGUAGES CXX)

#set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_BUILD_TYPE Release)

set (CMAKE_CXX_STANDARD_REQUIRED 20)

file (GLOB
			CPP_SOURCES "src/*.cpp"
			HPP_SOURCES "include/*.hpp")

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_library (Tokens STATIC src/MyStreams.cpp include/MyStreams.hpp)
add_library (Leksems STATIC src/Leksems.cpp include/Leksems.hpp)
target_link_libraries (Leksems PRIVATE Tokens)

add_executable (${PROJECT_NAME} src/main.cpp)
target_link_libraries (${PROJECT_NAME} PRIVATE Leksems)