cmake_minimum_required(VERSION 3.2...3.27.5)

project(super_mario)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=utf-8 -g -O0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(SOURCES
    main.cpp
    QGame.cpp
    QGame.h
    QGameWindow.cpp
    QGameWindow.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)

add_subdirectory(os_controls)
add_subdirectory(controller)
add_subdirectory(levels)
add_subdirectory(model)
add_subdirectory(objects)
add_subdirectory(ui)
