file(GLOB OBSERVER "*.h" "*.cpp")

add_library(observer ${OBSERVER})

set_property(TARGET observer PROPERTY FOLDER "Util")