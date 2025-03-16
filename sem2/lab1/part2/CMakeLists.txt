cmake_minimum_required(VERSION 3.16)
project(lab1_part2)

set(CMAKE_CXX_STANDARD 14)

find_package(VTK)
include(${VTK_USE_FILE}) 

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/mnt/d/gmsh/lib/libgmsh.so.4.13"
    INTERFACE_INCLUDE_DIRECTORIES "/mnt/d/gmsh/include"
)
set(GMSH_LIBRARY gmsh)

add_executable(${PROJECT_NAME} challengind.cpp)

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES} ${GMSH_LIBRARY})

