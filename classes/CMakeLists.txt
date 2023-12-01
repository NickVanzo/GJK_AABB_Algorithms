file(GLOB SOURCES "*.cpp" "*.h")
add_library(TestingAlgos ${SOURCES})
target_link_libraries(C__TestingGround TestingAlgos)
