cmake_minimum_required(VERSION 3.30.3)
project("Client")
# include("${CMAKE_SOURCE_DIR}/../CmakeConfig.cmake")

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(CURRENT_SYSTEM Linux)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CURRENT_SYSTEM Window)
ENDIF()

set(CMAKE_CXX_STANDARD 11)
set(name_app "Client")
set(BASE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(LIB_PATH "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/lib")
set(EXECUTABLE_OUTPUT_PATH "${BASE_PATH}/release/${CURRENT_SYSTEM}/bin")

message(STATUS "now path = ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Base_Path = ${BASE_PATH}")
message(STATUS "current system = ${CURRENT_SYSTEM}")

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
    ${name_app} 
    ${SRCS_MAIN}
)
target_link_libraries(
    ${name_app}
    ${LIBS}
    ${LIB_OTHER}
)
