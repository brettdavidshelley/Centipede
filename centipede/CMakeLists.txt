# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(centipede VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files (including LaserBlast.cpp)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/code/*.cpp)

# Add the executable
add_executable(centipede ${SOURCES})

# Include SFML header files
include_directories(${PROJECT_SOURCE_DIR}/../SFML/include)

# Link SFML library directories
link_directories(${PROJECT_SOURCE_DIR}/../SFML/lib)

# Link the executable to the SFML libraries
target_link_libraries(centipede PUBLIC sfml-graphics sfml-system sfml-window)

# Set target properties (for working directory)
set_target_properties(
    centipede PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${COMMON_OUTPUT_DIR}/bin"
)

# Copy resources (fonts, graphics, low res, sound) to the output directory
file(COPY ${PROJECT_SOURCE_DIR}/fonts
     DESTINATION "${COMMON_OUTPUT_DIR}/bin")
file(COPY ${PROJECT_SOURCE_DIR}/graphics
     DESTINATION "${COMMON_OUTPUT_DIR}/bin")

