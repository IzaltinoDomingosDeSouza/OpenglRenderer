#pragma onc

#include "../types.h"
#include "../window/window.h"

class AppCtx
{
public:
    explicit AppCtx(Window * window) : m_window{window} {}

    AppCtx(const AppCtx &) = delete;
    AppCtx& operator=(const AppCtx &) = delete;

    void set_title(const std::string & title)
    {
        m_window->set_title(title);
    }

    void set_screen_size(Size<size_t> size)
    {
        m_window->set_width(size.width); m_window->set_height(size.height);
    }

    const std::string & get_title() const
    {
        return m_window->get_title();
    }
    Size<size_t> get_screen_size() const
    {
        return {m_window->get_width(), m_window->get_height()};
    }

    const float get_aspect_ratio() const
    {
        auto size = get_screen_size();
        return static_cast<float>(size.width) / static_cast<float>(size.height);
    }
private:
    Window * m_window;
};