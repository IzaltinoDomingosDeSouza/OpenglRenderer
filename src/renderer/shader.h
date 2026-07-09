#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader() = default;
    ~Shader();

    Shader(const Shader & ) = delete;
    Shader & operator=(const Shader & ) = delete;

    void compile(std::string_view vertex_source,  std::string_view fragment_source);
    
    void bind() const;
    void unbind() const;
    
    void set_int(std::string_view name, int value);
    void set_float(std::string_view name, float value);
    void set_vec2(std::string_view name, const glm::vec2 & value);
    void set_vec3(std::string_view name, const glm::vec3 & value);
    void set_vec4(std::string_view name, const glm::vec4 & value);
    void set_mat4(std::string_view name, const glm::mat4 & matrix);
private:
    unsigned int _renderer_id;
    std::unordered_map<std::string, int> _uniform_location_cache;
    int get_uniform_location(std::string_view name);

};
