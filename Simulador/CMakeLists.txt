cmake_minimum_required(VERSION 3.14)
project(Simulador_de_trafego)

set(CMAKE_EXE_LINKER_FLAGS "-g -lbfd -ldl")

message( STATUS "*** Compilando programa principal ***")

file(GLOB SOURCES ../scr/*.cpp)

include_directories(
  ../include
  ../libs
)

link_directories(
  ../libs
)

enable_testing()

add_executable(
  Simulador_de_Trafego
  main.cpp
  ../src/Rodovia.cpp
  ../src/Simulador.cpp
  ../src/Veiculo.cpp
)

target_link_libraries(
  Simulador_de_Trafego
)