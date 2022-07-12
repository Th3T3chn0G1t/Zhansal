cmake_minimum_required(VERSION 3.23)

project(Zhansal)

set(EXPORT_COMPILE_COMMANDS true)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)


# Notcurses
	set(USE_DEFLATE OFF)
	set(USE_PANDOC OFF)
	set(USE_CXX ON)
	set(USE_DOCTEST OFF)
	set(USE_GPM ON)
	set(USE_POC OFF)
	set(BUILD_EXECUTABLES OFF)
	add_subdirectory(zhansal/vendor/notcurses)

	add_compile_definitions(NCPP_EXCEPTIONS_PLEASE)
	include_directories(zhansal/vendor/notcurses/include)
	link_libraries(notcurses-core notcurses notcurses++)
#

file(GLOB zhansal zhansal/*.cpp zhansal/include/*.hpp)
add_executable(zhansal.out ${zhansal})

