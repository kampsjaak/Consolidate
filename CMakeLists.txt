cmake_minimum_required(VERSION 3.18)

project(Consolidate)


set(LIB_EXT ".lib")

#meow
add_executable(meow)
file(GLOB_RECURSE meow_sources
    "src/*.h"
    "src/*.cpp"
)
target_sources(meow PUBLIC ${meow_sources})


#OpenGL
find_package(OpenGL REQUIRED)
target_include_directories(meow PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(meow PUBLIC ${OPENGL_LIBRARIES})


#GLFW
include(ExternalProject)
ExternalProject_Add(GLFW

	CMAKE_ARGS
		-DGLFW_BUILD_EXAMPLES=OFF
		-DGLFW_BUILD_TESTS=OFF
		-DGLFW_BUILD_DOCS=OFF
		-DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
	GIT_REPOSITORY https://github.com/glfw/glfw
	UPDATE_DISCONNECTED ON
)

ExternalProject_Get_Property(GLFW install_dir)
include_directories(${install_dir}/include)
target_link_libraries(meow PUBLIC ${install_dir}/lib/glfw3${LIB_EXT})
