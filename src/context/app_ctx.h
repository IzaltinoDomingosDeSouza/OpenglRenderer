#pragma once

#include "../core/types.h"
#include "../window/window.h"

class AppCtx
{
public:
    explicit AppCtx(Window * window) : _window{window}, _should_quit{false} {}

    AppCtx(const AppCtx &) = delete;
    AppCtx & operator=(const AppCtx &) = delete;

    void set_title(const std::string & title)
    {
        _window->set_title(title);
    }

    void set_screen_size(Size<size_t> size)
    {
        _window->set_width(size.width); _window->set_height(size.height);
    }

    const std::string & get_title() const
    {
        return _window->get_title();
    }
    Size<size_t> get_screen_size() const
    {
        return {_window->get_width(), _window->get_height()};
    }

    const float get_aspect_ratio() const
    {
        auto size = get_screen_size();
        return static_cast<float>(size.width) / static_cast<float>(size.height);
    }

    void disable_mouse_cursor()
    {
        _window->enable_mouse_cursor(false);
    }
    void enable_mouse_cursor()
    {
        _window->enable_mouse_cursor(true);
    }
    void quit()
    {
        _should_quit = true;
    }
    bool should_quit() const
    {
        return _should_quit || _window->should_close();
    }
private:
    Window * _window;
    bool _should_quit;
};