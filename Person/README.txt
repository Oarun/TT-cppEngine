//to set up command 
cmake -S . -B build

//build command 
cmake --build build

//execute command 
cd build . ctest

//generate code coverage
cd build . make gcov

//run individual tests by name
//make sure you are in the build directory
./projectname --gtest_filter*testname*

//generate code coverage report from any directory
gcovr -r . --xml xmlfilename.xml

//to exclude google test coverage we don't need, place the commensts like so 
//LCOV_EXCL_START
#include "gtest/gtest.h"
//LCOV_EXCL_STOP
