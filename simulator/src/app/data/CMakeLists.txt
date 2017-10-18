file( GLOB DATA "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/simulator/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/report/include")

add_library(data ${DATA})

target_link_libraries(data domain)

set_property(TARGET data PROPERTY FOLDER "App")