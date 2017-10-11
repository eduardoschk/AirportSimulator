file( GLOB TESTS "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/libraries/googletest/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/util")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/observer")
add_executable(tests ${TESTS})

target_link_libraries(tests google-test)
target_link_libraries(tests wind)
target_link_libraries(tests airport)
target_link_libraries(tests util)
target_link_libraries(tests observer)

set_property(TARGET tests PROPERTY FOLDER "Tests")