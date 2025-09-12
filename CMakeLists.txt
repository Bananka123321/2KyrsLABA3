cmake_minimum_required(VERSION 3.10.0)
project(LAB3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(LAB3 main.cpp)

set(CPACK_PACKAGE_NAME "LAB3")

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ivan Obuhov <vanushabrend@gmail.com>")
endif()

install(TARGETS LAB3 DESTINATION bin)
include(CPack)