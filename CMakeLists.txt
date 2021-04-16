# CMakeList.txt : CMake project for Consolidate, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Consolidate "Consolidate.cpp" "Consolidate.h" "Cube.cpp" "Mainclass.h" "Mainclass.cpp" "DeviceResources.h" "DeviceResources.cpp" "Renderer.h" "Renderer.cpp")

# TODO: Add tests and install targets if needed.
