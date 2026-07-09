#include <glad/glad.h>

#include "glfw_window.h"
#include "../core/log.h"

bool GLFWWindow::init(const std::string & title, size_t width, size_t height)
{
    _width = width;
    _height = height;
    _title = title;
    _vsync = false;

    if (!glfwInit())
    {
        log_critical("GLFW init fail");
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
    if(!_window)
    {
        log_critical("GLFW window creation fail");
        glfwTerminate();
        return false;
    }

    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow * window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        log_critical("GLAD fail");
        shutdown();
        return false;
    }

    return true;
}
void GLFWWindow::shutdown()
{
    if(_window)
        glfwDestroyWindow(_window);

    glfwTerminate();
}

bool GLFWWindow::should_close()
{
    return glfwWindowShouldClose(_window);
}

void GLFWWindow::poll_events()
{
    glfwPollEvents();
}

void GLFWWindow::swap_buffers()
{
    glfwSwapBuffers(_window);
}

void GLFWWindow::set_title(const std::string & title)
{
    _title = title;
}

const std::string & GLFWWindow::get_title() const
{
    return _title;
}

void GLFWWindow::set_width(size_t width)
{
    _width = width;
}

size_t GLFWWindow::get_width() const
{
    return _width;
}

void GLFWWindow::set_height(size_t height)
{
    _height = height;
}

size_t GLFWWindow::get_height() const
{
    return _height;
}

void GLFWWindow::apply_changes()
{
    if (!_window) return;

    glfwSetWindowTitle(_window, _title.c_str());
    glfwSetWindowSize(_window, static_cast<int>(_width), static_cast<int>(_height));
}
void GLFWWindow::set_vsync(bool enabled)
{
    glfwSwapInterval(enabled ? 1 : 0);
    _vsync = enabled;
}

bool GLFWWindow::is_vsync() const
{
    return _vsync;
}

void GLFWWindow::enable_mouse_cursor(bool enabled)
{
    if(enabled)
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    else
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void * GLFWWindow::get_native()
{
    return reinterpret_cast<void *>(_window);
}