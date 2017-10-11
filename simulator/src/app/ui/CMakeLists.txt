file( GLOB UI "*.cpp" "*.h")

add_library(ui ${UI})

set_property(TARGET ui PROPERTY FOLDER "App")