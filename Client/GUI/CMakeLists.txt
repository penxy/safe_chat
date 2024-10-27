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
ENDIF()

message("now system is ${CURRENT_SYSTEM}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/bin")
  
# Qt
find_package(Qt5Core REQUIRED PATHS "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/thirdparty/Qt5" NO_DEFAULT_PATH)
find_package(Qt5Widgets REQUIRED PATHS "${CMAKE_SOURCE_DIR}/release/${CURRENT_SYSTEM}/thirdparty/Qt5" NO_DEFAULT_PATH)
set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES})
message(STATUS "INCLUDE_Qt5: ${INCLUDE_Qt5}")
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_Qt5})
# qt_wrap_ui(SRCS_UI)


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
    ${SOURCE}
    # ${SRCS_UI}
    ${HEADER}
)

target_link_libraries(
    ${App}
    ${LIBS_Qt5}
)

