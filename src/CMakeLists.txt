# flex
find_package(FLEX REQUIRED)
flex_target(scan src/scan.l ${PROJECT_SOURCE_DIR}/src/lex.yy.c COMPILE_FLAGS --header-file="src/lex.yy.h")

# build!
file(GLOB C_SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)
add_library(picrin SHARED ${C_SOURCES} ${FLEX_scan_OUTPUTS})
target_link_libraries(picrin m xfile)