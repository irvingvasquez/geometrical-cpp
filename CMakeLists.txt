project(gcpp)

cmake_minimum_required(VERSION 3.16)

find_package(CGAL REQUIRED) 

# Required by CGAL
set(CMAKE_BUILD_TYPE Release)


# ----- Examples --------
set(BUILD_EXAMPLES true)

if(BUILD_EXAMPLES)
    set(EXAMPLES_DIR /examples/)

    add_executable(test_cgal ${PROJECT_SOURCE_DIR}${EXAMPLES_DIR}test_cgal.cpp)
    target_link_libraries(test_cgal CGAL::CGAL)
endif(BUILD_EXAMPLES)
