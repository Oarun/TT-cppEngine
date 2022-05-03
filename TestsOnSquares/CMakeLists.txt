# Here, the version of CMake must be AT LEAST 3.14 because of the commands used by Google Test integration.
cmake_minimum_required(VERSION 3.14)

# This will fetch the Gtest repo and install GoogleTests as a package, local to this project.
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Name the project
project(TestingSquares)


# Set the compiler options
	# This is mandatory for Google Tests to work alongside CMake.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
	# This is just used as a shorthand to make the file locations readable.
	# Replace "TestingSquares.dir" with project name, followed by '.dir' filetype
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/TestingSquares.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")


# Set Sources
	# This is the list of sources and executable names. Alter as necessary,
	# as though you were entering it into the add_executable command directly.
set(
	SOURCES
	Main.cpp
      )


# Create gcov target. Run coverage tests with 'make gcov'
	# Simply change "Main.cpp" to whatever main file you're compiling.
	# 	I don't really know what the grep line does so I don't even know
	# 	if that even effects compilation.
	#
	# In the "add_dependencies" command, change 'TestingSquares' to
	#	name specified in "project" command.
add_custom_target(
	gcov
	COMMAND mkdir -p coverage
	COMMAND ${CMAKE_MAKE_PROGRAM} test
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	)
add_custom_command(TARGET gcov
	COMMAND echo "=================== GCOV ===================="
	COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${OBJECT_DIR}
		| grep -A 5 "Main.cpp" > CoverageSummary.tmp
	COMMAND cat CoverageSummary.tmp
	COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
	)
add_dependencies(gcov TestingSquares)
# Make sure to clean coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Create the gcov-clean target. This cleans the build as well as generated
# .gcda and .gcno files
add_custom_target(scrub
	COMMAND ${CMAKE_MAKE_PROGRAM} clean
	COMMAND rm -f ${OBJECT_DIR}/*.gcno
	COMMAND rm -f ${OBJECT_DIR}/*.gcda
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	)


# Testing
enable_testing()



# Create Executable
add_executable(TestingSquares ${SOURCES})

# These are from GTest
	# Obviously change TestingSquares to project name, to link project to gtest
target_link_libraries(TestingSquares gtest_main)

# This will search provided cmake projects for tests.
include(GoogleTest)
gtest_discover_tests(TestingSquares)
