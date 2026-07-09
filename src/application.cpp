#include "application.h"
#include "context/context.h"
#include "window/glfw_window.h"
#include "window/glfw_input.h"
#include "renderer/renderer.h"

bool Application::init()
{
    _window = new GLFWWindow();
    if(!_window->init("", 512,512))
    {
        delete _window;
        return false;
    }

    _input.init(_window);
    _renderer = new Renderer;

    _context.application = new AppCtx(_window);
    _context.input = new InputCtx(&_input);
    _context.renderer = _renderer;

    _context.renderer->init();

    _game = create_gameapp();

    return true;
}

void Application::shutdown()
{

    destroy_gameapp(_game);

    delete _context.application;
    delete _context.input;

    delete _renderer;
    delete _window;
}

void Application::run()
{
    _game->on_init(&_context);
    _game->on_preload();

    _window->apply_changes();

    double last_time = glfwGetTime();
    while(!_context.application->should_quit())
    {
        double current_time = glfwGetTime();
        double delta_time = current_time - last_time;
        last_time = current_time;

        _window->poll_events();

        _game->on_update(static_cast<float>(delta_time));
        _game->on_render();

        _window->swap_buffers();
    }

    _game->on_shutdown();
}
