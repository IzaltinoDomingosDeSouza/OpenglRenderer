#pragma once

#include <vector>
#include <cstdint>

class Mesh
{
public:
    Mesh() = default;
    
    ~Mesh();

    Mesh(const Mesh &) = delete;
    Mesh & operator=(const Mesh &) = delete;

    void create(const std::vector<float> & vertices, const std::vector<unsigned int> & indices);
    void bind() const;
    void unbind() const;
    uint32_t get_index_count() const { return _index_count; }

private:
    uint32_t _vao = 0;
    uint32_t _vbo = 0;
    uint32_t _ebo = 0;
    
    uint32_t _index_count = 0;
};
