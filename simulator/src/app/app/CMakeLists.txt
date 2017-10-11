file( GLOB APP "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/util")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/observer")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/controllers")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/command")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/ui")

add_executable(app ${APP})

target_link_libraries(app wind)
target_link_libraries(app airport)
target_link_libraries(app util)
target_link_libraries(app observer)
target_link_libraries(app controllers)
target_link_libraries(app command)
target_link_libraries(app ui)

set_property(TARGET app PROPERTY FOLDER "App")