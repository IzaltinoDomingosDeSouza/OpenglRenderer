#pragma once

#include <string>
#include "../types.h"

class Window
{
public:
    virtual void init() = 0;
    virtual void shutdown() = 0;

    virtual void set_title(const std::string & title) = 0;
    virtual const std::string & get_title() const = 0;

    virtual void set_width(size_t width) = 0;
    virtual size_t get_width() const = 0;
    virtual void set_height(size_t height) = 0;
    virtual size_t get_height() const = 0;
};