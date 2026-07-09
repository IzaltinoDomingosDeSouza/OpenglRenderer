#include "glfw_input.h"

void GLFWInput::init(Window * window)
{
    _window = reinterpret_cast<GLFWwindow *>(window->get_native());
}

bool GLFWInput::is_key_pressed(int key_code)
{
    int state = glfwGetKey(_window, key_code);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool GLFWInput::is_key_just_pressed(int key_code)
{
    bool current = is_key_pressed(key_code);
    bool previous = _previous_states[key_code];

    _previous_states[key_code] = current;

    return current && !previous;
}

bool GLFWInput::is_mouse_button_pressed(int button)
{
    return glfwGetMouseButton(_window, button) == GLFW_PRESS;
}
bool GLFWInput::is_mouse_button_just_pressed(int button)
{
    bool current = is_mouse_button_pressed(button);
    bool previous = _mouse_previous_states[button];
    _mouse_previous_states[button] = current;
    return current && !previous;
}

void GLFWInput::get_mouse_position(double & x, double & y)
{
    glfwGetCursorPos(_window, &x, &y);
}
