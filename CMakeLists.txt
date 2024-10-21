# Set the minimun requirements.
cmake_minimum_required(VERSION 3.10)

# Set the project's name.
project(CPGE VERSION 0.0 LANGUAGES CXX)

# Set the C++11 required standard.
set(CXX_STANDARD 11)
set(CXX_EXTENSIONS OFF)
set(CXX_STANDARD_REQUIRED ON)

# Add subdirectoriesx
add_subdirectory(src)
