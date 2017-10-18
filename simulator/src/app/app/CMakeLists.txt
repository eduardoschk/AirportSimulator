file( GLOB APP "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/simulator/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/report/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/data")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/command")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/ui")

add_executable(app ${APP})

target_link_libraries(app data)
target_link_libraries(app command)
target_link_libraries(app ui)

set_property(TARGET app PROPERTY FOLDER "App")