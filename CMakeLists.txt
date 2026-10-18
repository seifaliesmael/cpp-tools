# Main Setup
cmake_minimum_required(VERSION 3.23)

project(CPPTools)

# At least C++17 for std::optional and GTest
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(CPPTools_Core STATIC)
target_sources(CPPTools_Core
    PRIVATE
        DiffEngine.cpp
        FileLoading.cpp
    PUBLIC
        FILE_SET myHeaders
        TYPE HEADERS
        BASE_DIRS
          .
        FILES
          ./DiffEngine.h
          ./FileLoading.h
          ./Types.h
)

add_executable(CPPTools)

target_link_libraries(CPPTools PRIVATE CPPTools_Core)

target_sources(CPPTools
	PRIVATE
		Main.cpp
)

# Testing
enable_testing()
add_subdirectory(tests)