add_library(opengl_renderer
    core/types.h
    main.cpp
    application.h
    application.cpp
    game_application.h
    context/context.h
    context/app_ctx.h
    window/window.h
    window/glfw_window.h window/glfw_window.cpp
    core/log.h
    core/log.cpp
)
target_link_libraries(opengl_renderer PUBLIC glad glfw)
target_include_directories(opengl_renderer PUBLIC
    .
    ${CMAKE_SOURCE_DIR}/thirdparty/glm
    ${CMAKE_SOURCE_DIR}/thirdparty/glad/include
    ${CMAKE_SOURCE_DIR}/thirdparty/glfw/include
)