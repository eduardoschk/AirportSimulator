cmake_minimum_required(VERSION 3.0)
project(AirportSimulator)

add_subdirectory(googletest)
add_subdirectory(googlemock)
add_subdirectory(test)
add_subdirectory(src)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

