cmake_minimum_required(VERSION 3.31)
project(fischhaken)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        MinHook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
        GIT_TAG master
)
FetchContent_MakeAvailable(minhook)

include_directories(${minhook_SOURCE_DIR}/include)

add_library(fischhaken SHARED dllmain.cpp)

target_link_libraries(fischhaken minhook)
