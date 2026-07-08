#include "game_application.h"

class Game : public GameApplication
{
public:
    void on_init(Context * context) override
    {
        _context = context;

        _context->application->set_title("Demo Game");
        _context->application->set_screen_size({800,600});
    }

    void on_shutdown() override
    {

    }

    void on_preload() override
    {

    }

    void on_update() override
    {

    }

    void on_render() override
    {

    }
private:
    Context * _context;
};
GameApplication * create_gameapp()
{
  return new Game();
}
void destroy_gameapp(GameApplication * game)
{
  delete game;
}
