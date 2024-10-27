cmake_minimum_required(VERSION 3.30.3)
project("Demo")
set(App "Demo")

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
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("CURRENT_SYSTEM = ${CURRENT_SYSTEM}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../release/${CURRENT_SYSTEM}/lib")
set(THIRD_PARTY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../release/${CURRENT_SYSTEM}/thirdparty")

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../release/${CURRENT_SYSTEM}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../release/${CURRENT_SYSTEM}/include/zdb")

FILE(GLOB SRCS_MAIN
   ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

set(LIBS ${LIBS} ${LIB_PATH}/libzdb.a)
message("LIBS = ${LIBS}")

SET(LIB_OTHER -lpthread -ldl)

add_executable(
    ${App} 
    ${SRCS_MAIN}
)
target_link_libraries(
    ${App}
    ${LIBS}
    ${LIB_OTHER}
)
