cmake_minimum_required(VERSION 3.0)
project(AirportSimulator)

option(BuildTests "BuildTests" OFF)

add_subdirectory(simulator)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

