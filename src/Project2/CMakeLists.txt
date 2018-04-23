# CMakeList.txt : CMake project for Project2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 2.8)

find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else (OPENMP_FOUND)
	message( FATAL_ERROR "OpenMP was not found." )
endif()

# Add source to this project's executable.
add_executable (Project2 Project2.cpp Utils.h Utils.cpp Body.h)

if(UNIX)
    target_link_libraries(Project2 stdc++fs)
endif(UNIX)

# TODO: Add tests and install targets if needed.
