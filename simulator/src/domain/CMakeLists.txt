file(GLOB AIRPORT   "${CMAKE_CURRENT_SOURCE_DIR}/airport/src/*.cpp" 
					"${CMAKE_CURRENT_SOURCE_DIR}/airport/include/*.h")
			  
file(GLOB WIND  "${CMAKE_CURRENT_SOURCE_DIR}/wind/src/*.cpp" 
				"${CMAKE_CURRENT_SOURCE_DIR}/wind/include/*.h")

file(GLOB SIMULATOR  "${CMAKE_CURRENT_SOURCE_DIR}/simulator/src/*.cpp" 
					 "${CMAKE_CURRENT_SOURCE_DIR}/simulator/include/*.h")
				  
file(GLOB REPORT  	"${CMAKE_CURRENT_SOURCE_DIR}/report/src/*.cpp" 
					"${CMAKE_CURRENT_SOURCE_DIR}/report/include/*.h")
			
include_directories("${CMAKE_SOURCE_DIR}/simulator/src/util")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/simulator/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/wind/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/airport/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/report/include")

file(GLOB EVENTS	"${CMAKE_CURRENT_SOURCE_DIR}/report/include/Event*"
					"${CMAKE_CURRENT_SOURCE_DIR}/report/src/Event*")
					
source_group( Events FILES ${EVENTS} )
					
file(GLOB REPORTS	"${CMAKE_CURRENT_SOURCE_DIR}/report/include/Report*"
					"${CMAKE_CURRENT_SOURCE_DIR}/report/src/Report*"
					"${CMAKE_CURRENT_SOURCE_DIR}/report/src/Log*"
					"${CMAKE_CURRENT_SOURCE_DIR}/report/include/Log*")
					
source_group( Reports FILES ${REPORTS} )
			
add_library(report ${REPORT})
add_library(airport ${AIRPORT})
add_library(wind ${WIND})

add_library(domain ${SIMULATOR})

target_link_libraries(domain util)
target_link_libraries(airport util)
target_link_libraries(wind util)

target_link_libraries(wind report)
target_link_libraries(airport report)
target_link_libraries(domain report)

target_link_libraries(domain airport)
target_link_libraries(domain wind)

set_property(TARGET airport PROPERTY FOLDER "Domain")
set_property(TARGET wind PROPERTY FOLDER "Domain")
set_property(TARGET domain PROPERTY FOLDER "Domain")
set_property(TARGET report PROPERTY FOLDER "Domain")