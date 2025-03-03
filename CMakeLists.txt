cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Algorithms VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
# Glob all .cpp files in the current directory
file(GLOB EXE_FILES
    "algorithms/*.cpp"
    "challenges/*.cpp"
    "cpugraphics/*.cpp"
    "idioms/*.cpp"
    "memory/*.cpp"
    "stl/*.cpp"
    "syntax/*.cpp"
    "templating/*.cpp"
    "textprocess/*.cpp"
)

# For each .cpp file, create an executable
foreach(EXE_FILE ${EXE_FILES})
  # Extract the file name without extension to name the executable
  get_filename_component(EXE_NAME ${EXE_FILE} NAME_WE)
  add_executable(${EXE_NAME} ${EXE_FILE})
endforeach()

if(MSVC)
  # target_compile_options(Algorithms PUBLIC "/ZI") # for 'Edit And Continue'
  # target_link_options(Algorithms PUBLIC "/INCREMENTAL") # faster building
endif()