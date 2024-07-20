# Allow inclusion only one time.
include_guard()

# Create a library.
add_library(CPGE System.cpp Hints.cpp Log.cpp)

# Set the libraries headers directory.
target_include_directories(CPGE PRIVATE ../include)

target_compile_options(CPGE PRIVATE -Wall -Werror)
