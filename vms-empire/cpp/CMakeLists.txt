project(vms-empire CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")

add_executable(vms-empire
	map.cpp
	unit.cpp
	test.cpp)
