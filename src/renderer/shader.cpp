#include <glad/glad.h>

#include "shader.h"
#include "../core/log.h"

Shader::~Shader()
{
    if(_renderer_id)
        glDeleteProgram(_renderer_id);
}

void Shader::compile(std::string_view vertex_source, std::string_view fragment_source)
{
    uint32_t vs = glCreateShader(GL_VERTEX_SHADER);
    uint32_t fs = glCreateShader(GL_FRAGMENT_SHADER);

    const char * vs_ptr = vertex_source.data();
    const char * fs_ptr = fragment_source.data();

    glShaderSource(vs, 1, &vs_ptr, nullptr);
    glShaderSource(fs, 1, &fs_ptr, nullptr);

    glCompileShader(vs);
    glCompileShader(fs);

    auto check_errors = [](uint32_t shader, const std::string& type)
    {
        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char info_log[1024];
            glGetShaderInfoLog(shader, 1024, nullptr, info_log);
            log_error(std::format("Shader compilation fail of :{} {} ", type , info_log));
        }
    };

    check_errors(vs, "VERTEX");
    check_errors(fs, "FRAGMENT");

    _renderer_id = glCreateProgram();
    glAttachShader(_renderer_id, vs);
    glAttachShader(_renderer_id, fs);
    glLinkProgram(_renderer_id);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::bind() const
{
    glUseProgram(_renderer_id);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

void Shader::set_int(std::string_view name, int value)
{
    glUniform1i(get_uniform_location(name), value);
}

void Shader::set_float(std::string_view name, float value)
{
    glUniform1f(get_uniform_location(name), value);
}

void Shader::set_vec2(std::string_view name, const glm::vec2 & value)
{
    glUniform2fv(get_uniform_location(name.data()), 1, glm::value_ptr(value));
}

void Shader::set_vec3(std::string_view name, const glm::vec3 & value)
{
    glUniform3fv(get_uniform_location(name.data()), 1, glm::value_ptr(value));
}

void Shader::set_vec4(std::string_view name, const glm::vec4 & value)
{
    glUniform4fv(get_uniform_location(name.data()), 1, glm::value_ptr(value));
}

void Shader::set_mat4(std::string_view name, const glm::mat4 & matrix)
{
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

int Shader::get_uniform_location(std::string_view name)
{
    std::string key(name);

    if (_uniform_location_cache.find(key) != _uniform_location_cache.end())
        return _uniform_location_cache[key];

    int location = glGetUniformLocation(_renderer_id, key.c_str());
    _uniform_location_cache[key] = location;
    return location;
}
