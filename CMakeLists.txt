cmake_minimum_required(VERSION 3.8)
project(MPL1)

set(CMAKE_CXX_STANDARD 14)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(MPL1 ${SOURCE_FILES})