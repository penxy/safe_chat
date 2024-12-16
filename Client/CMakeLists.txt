cmake_minimum_required(VERSION 3.29)
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

set(LIB_PATH ${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/release/${CMAKE_SYSTEM_NAME}/bin)
message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")

    FILE(GLOB LIBS
        ${LIB_PATH}/libcurl${CMAKE_SHARED_LIBRARY_SUFFIX}
    )
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(CMAKE_C_COMPILER "D:/DownLoad/MinGW/MinGW/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "D:/DownLoad/MinGW/MinGW/bin/g++.exe")
    set(Qt5_DIR D:\\QtCreator2\\5.12.9\\mingw73_64)
    
    FILE(GLOB LIBS
        ${LIB_PATH}/libcurl.lib
    )
ENDIF()
# -lpthread
find_package(Threads REQUIRED)
SET(LIBS_SYS ${LIBS_SYS} Threads::Threads)
message(STATUS "LIBS: ${LIBS}")

# Qt
find_package(Qt5Core REQUIRED PATHS ${Qt5_DIR})
find_package(Qt5Widgets REQUIRED PATHS ${Qt5_DIR})
find_package(Qt5 COMPONENTS Svg REQUIRED PATHS ${Qt5_DIR})
find_package(Qt5 COMPONENTS Sql REQUIRED PATHS ${Qt5_DIR})
find_package(Qt5 COMPONENTS Network REQUIRED PATHS ${Qt5_DIR})
find_package(Qt5 COMPONENTS Xml REQUIRED PATHS ${Qt5_DIR})
set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Svg_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5Svg_LIBRARIES} ${Qt5Sql_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Xml_LIBRARIES})
# .ui
list(APPEND CMAKE_AUTOMOC_SEARCH_PATHS "./src/widget/form/rmchatdialog.ui")
list(APPEND CMAKE_AUTOMOC_SEARCH_PATHS "./src/widget/form/addfrienddialog.ui")

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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Ftp/*.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Service/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Service/Net/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Chat/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Data/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Setting/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/widget/form/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/args.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/icons.qrc
)

message(STATUS "LIBS: ${LIBS}")
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