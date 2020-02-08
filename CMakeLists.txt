cmake_minimum_required(VERSION 3.7)
project(cw2)

#set(CMAKE_PREFIX_PATH "/home/twak/Qt/5.12.5") on some systems this is required

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CMAKE_CXX_STANDARD 11)

include_directories (${CMAKE_BINARY_DIR})

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

set(SOURCE_FILES tomeo.cpp the_player.cpp the_player.h the_button.cpp the_button.h two.cpp two.h one.cpp one.h pages.cpp pages.h three.cpp three.h sysWindow.cpp sysWindow.h mySlider.cpp mySlider.h)
add_executable(cw2 ${SOURCE_FILES})

target_link_libraries(cw2 Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)