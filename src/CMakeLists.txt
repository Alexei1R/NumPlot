
set(LIB_SRC
        NPlot/Scene/Scene.cpp
        NPlot/Scene/Scene.h
        NPlot/Utils/Logger.cpp
        NPlot/Utils/Logger.h
        NPlot/Utils/macros.h
        NPlot/Renderer/Window.h
        NPlot/Renderer/Window.cpp

        NPlot/Events/Event.h
        NPlot/Events/ImplEvent.h
)


add_library(NPlot ${LIB_SRC})

target_link_libraries(NPlot
        glad
        glfw
        glm
        spdlog
)
target_include_directories(NPlot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)




