cmake_minimum_required(VERSION 3.16)

project(uart LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)



add_executable(uart
	src/main.cpp
	src/UartRx.c
	src/UartTx.c
)

target_include_directories(uart
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(MSVC)
	target_compile_options(uart PRIVATE /W4)
else()
	target_compile_options(uart PRIVATE -Wall -Wextra -Wpedantic)
endif()
