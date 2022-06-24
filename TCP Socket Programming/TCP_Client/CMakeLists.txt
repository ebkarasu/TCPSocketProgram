cmake_minimum_required(VERSION 3.14)

project(TCP_Client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt5 COMPONENTS Network REQUIRED)

add_executable(TCP_Client main.cpp socket.cpp socket.h user.cpp user.h)

target_link_libraries(TCP_Client Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(TCP_Client Qt5::Network)
