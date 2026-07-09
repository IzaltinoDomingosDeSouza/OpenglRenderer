#pragma once

#include <glm/vec4.hpp>

class OpenglApi
{
public:
    void init();
    void clear(glm::vec4 color);
    void set_viewport(int x, int y, int width, int height);
    void draw_indexed(uint32_t index_count);
};