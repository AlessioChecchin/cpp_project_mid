# CMake version check
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(project_mid)

# Enable c++11 standard
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES
	src/main.cpp

	src/book.cpp
	src/date.cpp
	src/bookshelf.cpp

	src/test/test.cpp
	src/test/test_book.cpp
	src/test/test_date.cpp
	src/test/test_bookshelf.cpp
)


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(project_mid ${SOURCE_FILES})