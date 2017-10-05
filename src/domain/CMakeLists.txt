file(GLOB AIRPORT   "${CMAKE_CURRENT_SOURCE_DIR}/Airport/src/*.cpp" 
					"${CMAKE_CURRENT_SOURCE_DIR}/Airport/include/*.h")
				  
file(GLOB WIND  "${CMAKE_CURRENT_SOURCE_DIR}/Wind/src/*.cpp" 
			    "${CMAKE_CURRENT_SOURCE_DIR}/Wind/include/*.h")

				
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Airport/include")			
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Wind/include")
include_directories("${PROJECT_SOURCE_DIR}/src/util")
include_directories("${PROJECT_SOURCE_DIR}/src/observer")
				
add_library(wind ${WIND})
add_library(airport ${AIRPORT})

target_link_libraries (airport wind)
target_link_libraries (airport observer)
target_link_libraries (wind observer)

set_property(TARGET airport PROPERTY FOLDER "Airport")
set_property(TARGET wind PROPERTY FOLDER "Airport")


