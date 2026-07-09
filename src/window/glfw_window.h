#pragma once

#include "window.h"
#include <GLFW/glfw3.h>

class GLFWWindow : public Window
{
public:

    bool init(const std::string & title, size_t width, size_t height) override;
    void shutdown() override;

    bool should_close() override;
    void poll_events() override;
    void swap_buffers() override;

    void set_title(const std::string & title) override;
    const std::string & get_title() const override;

    void set_width(size_t width) override;
    size_t get_width() const override;

    void set_height(size_t height) override;
    size_t get_height() const override;

    void apply_changes() override;

    void set_vsync(bool enabled) override;
    bool is_vsync() const override;

    void enable_mouse_cursor(bool enabled) override;

    void * get_native() override;

private:
    GLFWwindow * _window = nullptr;
    std::string _title;
    size_t _width;
    size_t _height;
    bool _vsync;
};
