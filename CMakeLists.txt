cmake_minimum_required (VERSION 3.10)
project (rapidcheck_example)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup (TARGETS)
else ()
    message (WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_executable (rapidcheck_example main.cpp)
target_compile_features (rapidcheck_example PRIVATE cxx_std_17)
target_link_libraries (rapidcheck_example PRIVATE CONAN_PKG::rapidcheck)
