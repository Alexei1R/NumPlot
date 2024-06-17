




set(SOURCE
        main.cpp
)


add_executable(executable ${SOURCE})

target_link_libraries(executable
    NPlot
)
target_include_directories(executable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)




