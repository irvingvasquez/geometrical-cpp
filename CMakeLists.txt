project(gcpp)

cmake_minimum_required(VERSION 3.16)

find_package(CGAL REQUIRED) 

# Required by CGAL
set(CMAKE_BUILD_TYPE Release)

find_package(GMP REQUIRED)

include_directories(include)
set(SRC_GCPP src/maps.cpp)


#set(GCC_OTHER_FLAGS "-frounding-math")
#add_definitions(${GCC_OTHER_FLAGS})
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_OTHER_FLAGS}" )
#SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )
 
#set(UAVPLANNING_REQUIRED_LIBS ${CGAL_LIBRARY} ${GMP_LIBRARIES}) 


# ----- Examples --------
set(BUILD_EXAMPLES true)

if(BUILD_EXAMPLES)
    set(EXAMPLES_DIR /examples/)

    add_executable(test_cgal ${PROJECT_SOURCE_DIR}${EXAMPLES_DIR}test_cgal.cpp)
    target_link_libraries(test_cgal CGAL::CGAL)

    add_executable(perpendicular_path ${PROJECT_SOURCE_DIR}${EXAMPLES_DIR}perpendicular_path.cpp ${SRC_GCPP})
    target_link_libraries(perpendicular_path CGAL::CGAL)
endif(BUILD_EXAMPLES)
