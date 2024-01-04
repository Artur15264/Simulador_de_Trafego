cmake_minimum_required(VERSION 3.22.1)
project(Simulador_de_trafego)
add_executable(Simulador_Final main.cpp Veiculo.cpp Rodovia.cpp Simulador.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-g -lbfd -ldl")
