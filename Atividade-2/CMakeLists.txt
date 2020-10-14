# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Mola)

#
add_executable(Mola main.cpp)

# Especificar onde estao os header files
include_directories(controller.hpp, view.hpp, dados.hpp)

# Bibliotecas locais (estaticas)
add_library(control controller.cpp)
target_link_libraries(Mola control)
add_library(view view.cpp)
target_link_libraries(Mola view)
add_library(dados dados.cpp)
target_link_libraries(Mola dados)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(Mola SDL2)
target_link_libraries(Mola SDL2_image)

