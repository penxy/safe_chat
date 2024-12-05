cmake_minimum_required(VERSION 3.30)
project("GUI")
set(App "Client")
set(App_Test "test")# 测试用的

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g3 -ggdb -w")
add_compile_options(-g3)
add_compile_options(-w)

set(DEBUG_VERSION "DebugMode")
set(COMPILE_MODE ${RELEASE_VERSION})
string(TIMESTAMP COMPILE_TIME %Y-%m-%d_%H:%M)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
    SET(LIBS_SYS "-lpthread -ldl")        # -lpthread -ldl
ENDIF()
message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

set(LIB_PATH "${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/bin")
# Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Svg REQUIRED)
find_package(Qt5 COMPONENTS Sql REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

list(APPEND CMAKE_AUTOMOC_SEARCH_PATHS "./src/widget/form/rmchatdialog.ui")
list(APPEND CMAKE_AUTOMOC_SEARCH_PATHS "./src/widget/form/addfrienddialog.ui")

set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Svg_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES} ${Qt5Svg_LIBRARIES} ${Qt5Sql_LIBRARIES} ${Qt5Network_LIBRARIES})
message(STATUS "INCLUDE_Qt5: ${INCLUDE_Qt5}")
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${EXECUTABLE_OUTPUT_PATH}/../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Model)
include_directories(${INCLUDE_Qt5})

FILE(GLOB SOURCE 
    # src/*.cpp 
    # src/*/*.cpp 
    # src/*/*/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Base/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ListBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ListBar/Item/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ToolBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ChatBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ChatBar/bubble/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/TitleBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Card/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/test/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Add/*.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Service/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Service/Net/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Chat/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Data/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/widget/form/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/args.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/icons.qrc
)
FILE(GLOB LIBS
    ${LIB_PATH}/libgflags${CMAKE_STATIC_LIBRARY_SUFFIX}
)

add_executable(
    ${App}
    ${SOURCE}
)

target_link_libraries(
    ${App}
    ${LIBS_Qt5}
    ${LIBS}
    ${LIBS_SYS}
)

add_executable(
    ${App_Test}
    test.cpp
)
target_link_libraries(
    ${App_Test}
    ${LIBS_Qt5}
    ${LIBS}
    ${LIBS_SYS}
)