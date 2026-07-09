#pragma once

#include <window/window.h>
#include <GLFW/glfw3.h>

class GLFWInput
{
public:

    void init(Window * window);

    bool is_key_pressed(int key_code);
    bool is_key_just_pressed(int key_code);
    bool is_mouse_button_pressed(int button);
    bool is_mouse_button_just_pressed(int button);
    void get_mouse_position(double & x, double & y);
private:
    GLFWwindow * _window;
    std::unordered_map<int, bool> _previous_states;
    std::unordered_map<int, bool> _mouse_previous_states;
};
