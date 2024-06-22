

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE LIB_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Scene/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Utils/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Renderer/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Events/*.cpp"
)

file(GLOB_RECURSE LIB_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Scene/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Utils/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Renderer/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPlot/Events/*.h"
)

add_library(NPlot ${LIB_SRC} ${LIB_HEADERS})




target_link_libraries(NPlot
        glad
        glfw
        glm
        spdlog
)
target_include_directories(NPlot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)


