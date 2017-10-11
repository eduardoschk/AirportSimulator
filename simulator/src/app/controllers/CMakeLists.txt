file( GLOB CONTROLLERS "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/util")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/observer")

add_library(controllers ${CONTROLLERS})

target_link_libraries(controllers airport)
target_link_libraries(controllers wind)
target_link_libraries(controllers util)
target_link_libraries(controllers observer)

set_property(TARGET controllers PROPERTY FOLDER "App")
