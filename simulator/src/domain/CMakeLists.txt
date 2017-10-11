file(GLOB AIRPORT   "${CMAKE_CURRENT_SOURCE_DIR}/airport/src/*.cpp" 
					"${CMAKE_CURRENT_SOURCE_DIR}/airport/include/*.h")
				  
file(GLOB WIND  "${CMAKE_CURRENT_SOURCE_DIR}/wind/src/*.cpp" 
			    "${CMAKE_CURRENT_SOURCE_DIR}/wind/include/*.h")

				
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/airport/include")			
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/wind/include")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/util")
include_directories("${PROJECT_SOURCE_DIR}/simulator/src/observer")
				
add_library(wind ${WIND})
add_library(airport ${AIRPORT})

target_link_libraries (airport wind)
target_link_libraries (airport observer)
target_link_libraries (wind observer)

set_property(TARGET airport PROPERTY FOLDER "Airport")
set_property(TARGET wind PROPERTY FOLDER "Airport")


