#pragma once

#include <glm/matrix.hpp>

#include "backend/opengl_api.h"
#include "shader.h"
#include "mesh.h"

class Renderer
{
public:
    Renderer() = default;

    Renderer(const Renderer &) = delete;
    Renderer & operator=(const Renderer &) = delete;
    Renderer(Renderer &&) = delete;
    Renderer & operator=(Renderer &&) = delete;

    void clear(glm::vec4 color);
    void init();
    void submit(Mesh * mesh, Shader * shader, const glm::mat4 & model_matrix);
    void begin_scene(const glm::mat4 & view_projection_matrix);
    void end_scene();
private:
    OpenglApi _api;
    glm::mat4 _view_projection_matrix;
};