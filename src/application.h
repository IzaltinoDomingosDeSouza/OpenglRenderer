#pragma once

#include "game_application.h"

class Application
{
public:
    void init();
    void shutdown();
    void run();
private:
    Window * _window;
    Context _context;
    GameApplication * _game;
};