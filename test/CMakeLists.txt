file( GLOB TESTS "*.cpp" "*.h")

include_directories("${PROJECT_SOURCE_DIR}/googletest/include")
include_directories("${PROJECT_SOURCE_DIR}/googlemock/include")
include_directories("${PROJECT_SOURCE_DIR}/src/domain/Airport/include")
include_directories("${PROJECT_SOURCE_DIR}/src/domain/Wind/include")
add_executable(tests ${TESTS})

target_link_libraries(tests google-test)
target_link_libraries(tests google-mock)
target_link_libraries(tests wind)
target_link_libraries(tests airport)

set_property(TARGET tests PROPERTY FOLDER "Tests")