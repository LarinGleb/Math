cmake_minimum_required(VERSION 3.16)

#--------- GET PROPETIES ---------
get_property(TIME VARIABLE PROPERTY TIME)
get_property(Log VARIABLE PROPERTY Log)

enable_testing()

include_directories(gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
Log("[${TIME}] tests/CMakeLists.txt: added includes to gtest")


add_executable(unit_tests unit/basic_init_matrix_test.cpp)
target_link_libraries(unit_tests gtest gtest_main gmock pthread)
Log("[${TIME}] tests/CMakeLists.txt: linked libs for unit tests")


add_test(unit_tests unit_tests)
Log("[${TIME}] tests/CMakeLists.txt: added unit tests")