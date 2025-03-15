cmake_minimum_required(VERSION 3.10.0)
project(spamscript VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDART_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE SOURCES source/*.cpp source/*.hpp)

include_directories(source)

add_executable(spamscript ${SOURCES})

target_link_libraries(spamscript Qt::Core Qt::Widgets)
