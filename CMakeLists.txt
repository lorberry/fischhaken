cmake_minimum_required(VERSION 3.31)
project(fischhaken)

set(CMAKE_CXX_STANDARD 20)

add_library(fischhaken SHARED library.cpp)

include(FetchContent)

FetchContent_Declare(
        minhook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
)
FetchContent_MakeAvailable()
