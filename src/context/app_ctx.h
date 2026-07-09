#pragma onc

#include "../core/types.h"
#include "../window/window.h"

class AppCtx
{
public:
    explicit AppCtx(Window * window) : _window{window} {}

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
private:
    Window * _window;
};