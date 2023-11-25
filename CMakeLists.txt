# CMake version check
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(project_med)

# Enable c++11 standard
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# check if i want to run tests
if(${TARGET} STREQUAL "test")
	include("./src/test/${PATH}/source.cmake")

# otherwise it builds the main project
else()
	
	# Add main.cpp file of the project root directory as a source file
	set(SOURCE_FILES
		src/main.cpp 
		src/Book.cpp
		src/Date.cpp
		#src/my_vector.cpp
	)

endif()

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(project_med ${SOURCE_FILES})