file( GLOB COMMAND "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/ui")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/data")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/simulator/include")

add_library(command ${COMMAND})

target_link_libraries(command ui)
target_link_libraries(command data)

set_property(TARGET command PROPERTY FOLDER "App")