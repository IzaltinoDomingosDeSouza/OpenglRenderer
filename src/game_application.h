#pragma once

#include "context/context.h"

class GameApplication
{
public:
    virtual void on_init(Context * context) = 0;
    virtual void on_shutdown() = 0;
    virtual void on_preload() = 0;
    virtual void on_update() = 0;
    virtual void on_render() = 0;
};

GameApplication * create_gameapp();
void destroy_gameapp(GameApplication * game);