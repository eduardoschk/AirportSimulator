file( GLOB COMMAND "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/src/app/ui")

add_library(command ${COMMAND})

target_link_libraries(command ui)

set_property(TARGET command PROPERTY FOLDER "App")