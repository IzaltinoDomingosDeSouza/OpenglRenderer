#include "renderer.h"
void Renderer::init()
{
    _api.init();
}

void Renderer::clear(glm::vec4 color)
{
    _api.clear(color);
}

void Renderer::submit(Mesh * mesh, Shader * shader, const glm::mat4 & model_matrix)
{

    shader->bind();

    shader->set_mat4("u_ViewProjection", _view_projection_matrix);
    shader->set_mat4("u_Transform", model_matrix);

    mesh->bind();
    _api.draw_indexed(mesh->get_index_count());
    mesh->unbind();
}

void Renderer::begin_scene(const glm::mat4 & view_projection_matrix)
{
    _view_projection_matrix = view_projection_matrix;
}

void Renderer::end_scene()
{

}
