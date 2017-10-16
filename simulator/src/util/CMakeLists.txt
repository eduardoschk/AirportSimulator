file(GLOB UTIL "*.h" "*.cpp")

add_library(util ${UTIL})

set_property(TARGET util PROPERTY FOLDER "Util")