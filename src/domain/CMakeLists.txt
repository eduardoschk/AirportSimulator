file(GLOB AIRPORT   "${CMAKE_CURRENT_SOURCE_DIR}/Airport/src/*.cpp" 
					"${CMAKE_CURRENT_SOURCE_DIR}/Airport/include/*.h")
				  
file(GLOB WIND  "${CMAKE_CURRENT_SOURCE_DIR}/Wind/src/*.cpp" 
			    "${CMAKE_CURRENT_SOURCE_DIR}/Wind/include/*.h")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Wind/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Airport/include")
				
add_library(wind ${WIND})

add_library(airport ${AIRPORT})

target_link_libraries (airport wind)

set_property(TARGET airport PROPERTY FOLDER "Airport/Airport")
set_property(TARGET wind PROPERTY FOLDER "Airport/Wind")