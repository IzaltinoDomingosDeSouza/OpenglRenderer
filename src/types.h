#pragma once

#include <cstdint>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <string_view>

template <typename T>
struct Size
{
    T width = 0;
    T height = 0;
};

template <typename T>
struct Rectangle
{
    T x = 0;
    T y = 0;
    T width = 0;
    T height = 0;
};