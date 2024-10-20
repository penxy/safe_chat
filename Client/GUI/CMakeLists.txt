cmake_minimum_required(VERSION 3.30)
project("GUI")
set(App "GUI")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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
  
# 查找 Qt 组件  
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES})
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_Qt5})

set(SOURCE 
    src/main.cpp
    src/widget_base.cpp
    src/widget_head.cpp
    src/widget_login.cpp
)
set(HEADER
    include/widget_base.h
    include/widget_const.h
    include/widget_head.h
    include/widget_login.h
)
add_executable(
    ${App}
    ${HEADER}
    ${SOURCE}
)

target_link_libraries(
    ${App}
    ${LIBS_Qt5}
)

