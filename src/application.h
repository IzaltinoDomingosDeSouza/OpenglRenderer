#pragma once

#include "game_application.h"

class Application
{
public:
    bool init();
    void shutdown();
    void run();
private:
    bool is_running;
    Window * _window;
    Context _context;
    GameApplication * _game;
};