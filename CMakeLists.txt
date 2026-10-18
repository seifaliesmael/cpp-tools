cmake_minimum_required(VERSION 3.23)

project(CPPTools)

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
)

add_executable(CPPTools)
target_compile_features(CPPTools_Core PUBLIC cxx_std_20)

target_link_libraries(CPPTools PRIVATE CPPTools_Core)

target_sources(CPPTools
	PRIVATE
		Main.cpp

)