cmake_minimum_required(VERSION 3.17)
project(cal-2021-g66)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)


file(GLOB_RECURSE INC "include/*.h")
file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE GV "lib/GraphViewerCpp/src/*.cpp")

add_executable(cal-2021-g66 ${INC} ${SRC} ${GV})

target_link_libraries(cal-2021-g66 graphviewer)