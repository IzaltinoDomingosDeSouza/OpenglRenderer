#pragma once

#include "game_application.h"

class Application
{
public:
    bool init();
    void shutdown();
    void run();
private:
    Window * _window;
    GLFWInput _input;
    Context _context;
    GameApplication * _game;
};