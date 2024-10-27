cmake_minimum_required(VERSION 3.30.3)
project("Client")
set(App "Client")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS_RELEASE "-O0 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

set(DEBUG_VERSION "DebugMode")
set(COMPILE_MODE ${RELEASE_VERSION})                    # 编译模式
string(TIMESTAMP COMPILE_TIME %Y-%m-%d_%H:%M)           # 生成编译时间

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
    SET(LIB_OTHER ${LIB_OTHER} "-lpthread -ldl")        # -lpthread -ldl

ENDIF()
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/bin")
set(LIB_PATH "${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/lib")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/utils SRCS_UTILS)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${EXECUTABLE_OUTPUT_PATH}/../include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

FILE(GLOB SRCS_MAIN
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

SET(LIBS ${LIBS} "${LIB_PATH}/libcjson${CMAKE_SHARED_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libcurl${CMAKE_SHARED_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libgflags${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libfmt${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libhv${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libsqlite3${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libSQLiteCpp${CMAKE_STATIC_LIBRARY_SUFFIX}")
SET(LIBS ${LIBS} "${LIB_PATH}/libcryptopp${CMAKE_STATIC_LIBRARY_SUFFIX}")

add_executable(
    ${App} 
    ${SRCS_MAIN}
    ${SRCS_UTILS}
)
target_link_libraries(
    ${App}
    ${LIBS}
    ${LIB_OTHER}
)
