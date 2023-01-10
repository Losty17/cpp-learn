file(
    GLOB
    HEADER_FILES
    CONFIGURE_DEPENDS
    "*.h"
    "*.hpp"
    "**/*.h"
    "**/**.hpp"
)

file(
    GLOB
    SOURCE_FILES
    CONFIGURE_DEPENDS
    "*.cc"
    "*.cpp"
    "**/*.cc"
    "**/*.cpp"
)

add_executable(
    ${CMAKE_PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_link_libraries(${CMAKE_PROJECT_NAME} raylib)