# Testing Setup

# GoogleTest boilerplate
#-----------------------------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#-----------------------------------------------------------------------------------------------

add_executable(CPPTools_Tests)

target_sources(CPPTools_Tests
	PRIVATE
		tests_diffengine.cpp
)
target_link_libraries(CPPTools_Tests
	PRIVATE
		CPPTools_Core
		GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CPPTools_Tests)