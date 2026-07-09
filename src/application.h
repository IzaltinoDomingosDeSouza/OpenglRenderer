#pragma once

#include "game_application.h"
#include "window/window.h"
#include "window/glfw_input.h"
#include "context/context.h"
#include "renderer/renderer.h"

class Application
{
public:
    bool init();
    void shutdown();
    void run();
private:
    Window * _window;
    GLFWInput _input;
    Renderer *_renderer;
    Context _context;
    GameApplication * _game;
};