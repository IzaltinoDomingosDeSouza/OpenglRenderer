#pragma once

#include "../window/glfw_input.h"

#include <string>
#include <unordered_map>

enum class InputType { Keyboard, Mouse };

struct Binding
{
    InputType type;
    int code;
};

class InputCtx
{
public:
    explicit InputCtx(GLFWInput * input) : _input{input} {}

    InputCtx(const InputCtx &) = delete;
    InputCtx & operator=(const InputCtx &) = delete;

    bool is_key_down(int key_code) { return _input->is_key_pressed(key_code); }
    bool is_key_triggered(int key_code) { return _input->is_key_just_pressed(key_code); }
    bool is_mouse_down(int button) { return _input->is_mouse_button_pressed(button); }
    bool is_mouse_triggered(int button) const { return _input->is_mouse_button_just_pressed(button); }
    void get_mouse_position(double & x, double & y) { _input->get_mouse_position(x, y); }

    void get_mouse_delta(double & dx, double & dy) const
    {
        double current_x, current_y;
        _input->get_mouse_position(current_x, current_y);

        static double last_x = current_x;
        static double last_y = current_y;

        dx = current_x - last_x;
        dy = current_y - last_y;

        last_x = current_x;
        last_y = current_y;
    }

    void bind_action(const std::string& action, int key)
    {
        _action_map[action] = {InputType::Keyboard, key};
    }

    void bind_mouse_action(const std::string& action, int button)
    {
        _action_map[action] = {InputType::Mouse, button};
    }

    bool is_action_triggered(const std::string& action) const
    {
        auto it = _action_map.find(action);
        if (it != _action_map.end())
        {
            const Binding & bind = it->second;

            if(bind.type == InputType::Keyboard)
            {
                return _input->is_key_just_pressed(bind.code);
            }else if(bind.type == InputType::Mouse)
            {
                return _input->is_mouse_button_just_pressed(bind.code);
            }
        }
        return false;
    }
private:
    GLFWInput * _input;
    std::unordered_map<std::string, Binding> _action_map;
};
