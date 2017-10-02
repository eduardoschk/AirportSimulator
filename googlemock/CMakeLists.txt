set(google_mock_include_dirs
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${google_mock_include_dirs})
file(GLOB_RECURSE google_mock_headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
set(google_mock_sources src/gmock-all.cc src/gmock_main.cc)

include_directories("${PROJECT_SOURCE_DIR}/googletest/include")

add_library(google-mock STATIC ${google_mock_sources} ${google_mock_headers})

target_link_libraries(google-mock google-test)

set_property(TARGET google-mock PROPERTY FOLDER "Google/Google Mock")