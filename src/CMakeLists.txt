add_library(opengl_renderer
    core/types.h
    core/log.h
    core/log.cpp
    main.cpp
    application.h
    application.cpp
    game_application.h
    context/context.h
    context/app_ctx.h
    context/input_ctx.h
    window/window.h
    window/glfw_window.h window/glfw_window.cpp
    window/glfw_input.h window/glfw_input.cpp
    renderer/backend/opengl_api.h
    renderer/backend/opengl_api.cpp
    renderer/mesh.h
    renderer/mesh.cpp
    renderer/shader.h
    renderer/shader.cpp
    renderer/renderer.h
    renderer/renderer.cpp
)
target_link_libraries(opengl_renderer PUBLIC glad glfw)
target_include_directories(opengl_renderer PUBLIC
    .
    ${CMAKE_SOURCE_DIR}/thirdparty/glm
    ${CMAKE_SOURCE_DIR}/thirdparty/glad/include
    ${CMAKE_SOURCE_DIR}/thirdparty/glfw/include
)