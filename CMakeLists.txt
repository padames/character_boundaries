cmake_minimum_required(VERSION  3.28)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always -std=c++17 -Wall -g")


project(characterBoundaries)

add_executable(cbd main.cpp ) 

# ICU Components Reference:
# https://cmake.org/cmake/help/latest/module/FindICU.html
# ICU components = data, i18n, io, le, lx, test, tu and uc.

find_package(ICU 77.0 COMPONENTS data uc i18n io REQUIRED)

# Link using the imported target names (ICU::uc, ICU::i18n, etc.)

target_link_libraries( cbd PRIVATE ICU::io ICU::data ICU::uc ICU::i18n) 
