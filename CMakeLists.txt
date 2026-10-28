cmake_minimum_required(VERSION 3.16)
project(h0_websocket_reconstruction LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# 只做对象编译。重建代码引用 libc / zlib 符号但没有可链接入口，
# 目标只是验证"能不能作为 C++17 解析"。
foreach(lib H0WS2 H0WS3)
    file(GLOB TU_FILES "${CMAKE_CURRENT_SOURCE_DIR}/reconstructed_cpp/${lib}/${lib}_tu/*.cpp")
    add_library(${lib} OBJECT ${TU_FILES})
    target_include_directories(${lib} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/reconstructed_cpp/${lib}")
endforeach()
