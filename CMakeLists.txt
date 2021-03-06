cmake_minimum_required(VERSION 2.8)

PROJECT(picrin)

# load extra cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# ----

# git submodule update --init
find_package(Git REQUIRED)
execute_process(
  COMMAND ${GIT_EXECUTABLE} submodule update --init
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c99")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG=1")
include_directories(include extlib)

# build picrin
include(piclib/CMakeLists.txt)
include(contrib/CMakeLists.txt)
include(src/CMakeLists.txt)
include(tools/CMakeLists.txt)

# ----

# $ make run
add_custom_target(run bin/picrin DEPENDS repl)

# $ make no-act
add_custom_target(no-act bin/picrin -e '' > /dev/null DEPENDS repl)

# $ make tak
add_custom_target(tak bin/picrin etc/tak.scm DEPENDS repl)

# $ make lines
add_custom_target(lines find . -name "*.[chyl]" | xargs wc -l WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
