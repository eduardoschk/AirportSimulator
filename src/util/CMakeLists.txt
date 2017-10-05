file(GLOB UTIL "*.h" "*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/src/observer")

add_library(util ${UTIL})

target_link_libraries(util observer)

set_property(TARGET util PROPERTY FOLDER "Util")