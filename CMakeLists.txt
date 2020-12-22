cmake_minimum_required(VERSION 3.14.0)
project(json VERSION 0.1.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

option(ENABLE_UNIT_TESTING "Enable unit testing" ON)

if(WIN32)
	set(BOOST_ROOT "D:/boost_1_75_0")
	set(BOOST_INCLUDEDIR "D:/boost_1_75_0")
	set(BOOST_LIBRARYDIR "D:/boost_1_75_0/stage/x64/lib")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(Boost_USE_DEBUG_LIBS	OFF)
	set(Boost_USE_RELEASE_LIBS	ON)
endif()
set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED		ON)
set(Boost_USE_STATIC_RUNTIME	OFF)

find_package(Boost COMPONENTS unit_test_framework nowide json REQUIRED)
find_package(Threads REQUIRED)

add_subdirectory(json)

if(ENABLE_UNIT_TESTING AND NOT IS_SUBPROJECT)
	add_subdirectory(tests)
endif()
