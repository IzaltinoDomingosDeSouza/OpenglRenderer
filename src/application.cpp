#include "application.h"
#include "context/context.h"

#include "log.h"

void Application::init()
{
    log_info("Application testing log");
    log_error("Application testing log");
    log_critical("Application testing log");

    _context.application = new AppCtx(_window);

    _game = create_gameapp();
}
void Application::shutdown()
{

    destroy_gameapp(_game);

    delete _context.application;
}
void Application::run()
{

}
