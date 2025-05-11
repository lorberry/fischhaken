cmake_minimum_required(VERSION 3.31)
project(fischhaken)

set(CMAKE_CXX_STANDARD 20)

find_package(JNI REQUIRED)

include(FetchContent)
FetchContent_Declare(
        MinHook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
        GIT_TAG master
)
FetchContent_MakeAvailable(minhook)

include_directories(${CMAKE_SOURCE_DIR}/jni)
include_directories(${minhook_SOURCE_DIR}/include)

add_library(fischhaken SHARED dllmain.cpp
        jvm.cpp
        jvm.h
        sdk/minecraft/minecraft.cpp
        sdk/minecraft/minecraft.h
        sdk/classes/classes.h
        sdk/classes/classes.cpp
        sdk/minecraft/entity.cpp
        sdk/minecraft/entity.h
        hooks/Hooks.cpp
        hooks/Hooks.h
)

target_link_libraries(fischhaken PRIVATE minhook)
target_link_libraries(fischhaken PRIVATE ${JNI_LIBRARIES} ${CMAKE_SOURCE_DIR}/jni/jvm.lib)
