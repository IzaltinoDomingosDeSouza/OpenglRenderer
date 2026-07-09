#include <glad/glad.h>

#include "application.h"
#include "context/context.h"
#include "window/glfw_window.h"

bool Application::init()
{
    _window = new GLFWWindow();
    if(!_window->init("", 512,512))
    {
        delete _window;
        return false;
    }

    _context.application = new AppCtx(_window);

    _game = create_gameapp();

    is_running = true;

    return true;
}

void Application::shutdown()
{

    destroy_gameapp(_game);

    delete _context.application;
}

void Application::run()
{
    _game->on_init(&_context);
    _game->on_preload();

    _window->apply_changes();

    double last_time = glfwGetTime();
    while(!_window->should_close())
    {
        double current_time = glfwGetTime();
        double delta_time = current_time - last_time;
        last_time = current_time;

        _window->poll_events();

        _game->on_update(static_cast<float>(delta_time));

        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        _game->on_render();

        _window->swap_buffers();
    }

    _game->on_shutdown();
}
