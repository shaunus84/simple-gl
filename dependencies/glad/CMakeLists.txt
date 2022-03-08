project(glad LANGUAGES CXX)

add_library(glad STATIC
    src/glad.c
    include/glad/glad.h
    include/KHR/khrplatform.h)

target_include_directories(glad
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)
