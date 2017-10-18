add_subdirectory(domain)
if(NOT ${BuildTests})
	add_subdirectory(app)
endif()