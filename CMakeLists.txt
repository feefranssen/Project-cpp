cmake_minimum_required(VERSION 3.16)

project(cpp_eindproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_eindproject main.cpp
    character.h
    enemy.h
    hero.h
    weapon.h
    character.cpp
    enemy.cpp
    hero.cpp
    weapon.cpp)

include(GNUInstallDirs)
install(TARGETS cpp_eindproject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
