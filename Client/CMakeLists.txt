cmake_minimum_required(VERSION 3.30.3)
project("Client")
set(App "Client")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(CURRENT_SYSTEM Linux)
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CURRENT_SYSTEM Window)
    set(CMAKE_C_COMPILER "D:/DownLoad/MinGW/MinGW/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "D:/DownLoad/MinGW/MinGW/bin/g++.exe")
ENDIF()

message("now system is ${CURRENT_SYSTEM}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/bin")

set(BASE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(LIB_PATH "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/lib")

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${EXECUTABLE_OUTPUT_PATH}/../include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

FILE(GLOB SRCS_MAIN
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

SET(LIBS ${LIBS} "${LIB_PATH}/libcjson${CMAKE_SHARED_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libcurl${CMAKE_SHARED_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libfmt${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libgflags${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libhv${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libgmssl${CMAKE_SHARED_LIBRARY_SUFFIX}")

SET(LIB_OTHER ${LIB_OTHER} -lpthread)
message(STATUS "LIBS = ${LIBS}")

add_executable(
    ${App} 
    ${SRCS_MAIN}
)
target_link_libraries(
    ${App}
    ${LIBS}
    ${LIB_OTHER}
)
