#pragma once

#include <string>
#include "../core/types.h"

class Window
{
public:
    Window() = default;
    virtual ~Window() = default;

    Window(const Window &) = delete;
    Window & operator=(const Window &) = delete;
    Window(Window &&) = delete;
    Window & operator=(Window &&) = delete;

    virtual bool init(const std::string & title, size_t width, size_t height) = 0;
    virtual void shutdown() = 0;

    virtual bool should_close() = 0;
    virtual void poll_events() = 0;
    virtual void swap_buffers() = 0;

    virtual void set_title(const std::string & title) = 0;
    virtual const std::string & get_title() const = 0;

    virtual void set_width(size_t width) = 0;
    virtual size_t get_width() const = 0;
    virtual void set_height(size_t height) = 0;
    virtual size_t get_height() const = 0;

    virtual void set_vsync(bool enabled) = 0;
    virtual bool is_vsync() const = 0;

    virtual void apply_changes() = 0;

    virtual void enable_mouse_cursor(bool enabled) = 0;

    virtual void * get_native() = 0;
};