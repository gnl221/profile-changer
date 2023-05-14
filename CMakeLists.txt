cmake_minimum_required(VERSION 3.25)
project(profile_changer)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(src)

add_executable(profile_changer
        src/main.cpp
        src/MainWindow.cpp
        src/MainWindow.h
        src/MainWindow.ui
        src/Profile.cpp
        src/Profile.h
        tests/MainWindow_tests.cpp
        tests/Profile_tests.cpp)

target_link_libraries(profile_changer Qt5::Widgets)