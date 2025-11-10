cmake_minimum_required(VERSION 3.16)

project(eindproject_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(eindproject_cpp main.cpp
    character.h
    hero.h
    enemy.h
    weapon.h)

include(GNUInstallDirs)
install(TARGETS eindproject_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
