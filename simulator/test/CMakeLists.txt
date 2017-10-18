file( GLOB TESTS "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/simulator/libraries/googletest/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/airport/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/simulator/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/domain/report/include")
add_executable(tests ${TESTS})

target_link_libraries(tests google-test)
target_link_libraries(tests domain)

set_property(TARGET tests PROPERTY FOLDER "Tests")