cmake_minimum_required(VERSION 3.14)
project(Testes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

add_custom_target(coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    COMMAND lcov --directory . --capture --output-file coverage.info
    COMMAND lcov --remove coverage.info '/usr/*' --output-file coverage.info
    COMMAND lcov --list coverage.info
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

message( STATUS "*** Compilando testes unitários ***")

file(GLOB TEST_SOURCES ../src/*.cpp)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(
  ../include
)

enable_testing()

add_executable(
  teste_final
  Teste_Rodovia.cpp
  ../src/Rodovia.cpp
  Teste_Simulador.cpp
  ../src/Simulador.cpp
  Teste_Veiculo.cpp
  ../src/Veiculo.cpp
)
target_link_libraries(
  teste_final
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(teste_final)

