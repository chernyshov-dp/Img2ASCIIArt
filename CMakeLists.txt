cmake_minimum_required(VERSION 3.10)
project(Img2ASCIIArt)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/local/include")

link_directories("/usr/local/lib")

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})

add_executable(Img2ASCIIArt src/main.cpp)
target_link_libraries(Img2ASCIIArt ${PNG_LIBRARIES})
