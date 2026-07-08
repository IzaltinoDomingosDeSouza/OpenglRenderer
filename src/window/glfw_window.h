#pragma once

#include "window.h"
#include <GLFW/glfw3.h>

class GLFWWindow : public Window
{
public:
    void init() override;
    void shutdown() override;
private:
    GLFWwindow * _window;
};
