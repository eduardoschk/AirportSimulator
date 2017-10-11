file( GLOB DATA "*.cpp" "*.h")

add_library(data ${DATA})

set_property(TARGET data PROPERTY FOLDER "App")