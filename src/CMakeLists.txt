# CMake minimun version required.
cmake_minimum_required(VERSION 3.7)

# Set the project's name.
project(
  CPGE
  VERSION 0.0.0.1
  LANGUAGES CXX)

# Set language standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Add the library subdurectory.
add_subdirectory(lib)
