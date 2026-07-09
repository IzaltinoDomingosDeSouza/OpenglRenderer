#include "mesh.h"
#include <glad/glad.h>

Mesh::~Mesh()
{
    if(_vao)
        glDeleteVertexArrays(1, &_vao);

    if(_vbo)
        glDeleteBuffers(1, &_vbo);

    if(_ebo)
        glDeleteBuffers(1, &_ebo);
}

void Mesh::create(const std::vector<float> &vertices, const std::vector<unsigned int> &indices)
{
    _index_count = static_cast<uint32_t>(indices.size());

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    GLsizei stride = 8 * sizeof(float);

    // Position (Location 0)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);

    // Normals (Location 1)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));

    // UVs (Location 2)
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));

    glBindVertexArray(0);
}

void Mesh::bind() const
{
    glBindVertexArray(_vao);
}

void Mesh::unbind() const
{
    glBindVertexArray(0);
}