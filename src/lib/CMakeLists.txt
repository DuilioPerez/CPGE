# Allow inclusion only one time.
include_guard()

# Get the list of the files to compile.
file(GLOB fileList *.cpp)

# Create a library.
add_library(CPGE ${fileList})

# Set the libraries headers directory.
target_include_directories(CPGE PRIVATE ../include)

target_compile_options(CPGE PUBLIC -Wall -Werror)
