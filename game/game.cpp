#include <core/log.h>
#include <game_application.h>

class Game : public GameApplication
{
public:
    void on_init(Context * context) override
    {
        _context = context;

        _context->application->set_title("Demo Game");
        _context->application->set_screen_size({800,600});
        _context->application->enable_mouse_cursor();

        context->input->bind_action("Quit", GLFW_KEY_ESCAPE);

        std::string_view vertex_source = R"(#version 330 core
                                            layout(location = 0) in vec3 aPos;
                                            layout(location = 1) in vec3 aNormal;
                                            layout(location = 2) in vec2 aTexCoord;

                                            uniform mat4 u_ViewProjection;
                                            uniform mat4 u_Transform;

                                            void main() {
                                                gl_Position = u_ViewProjection * u_Transform * vec4(aPos, 1.0);
                                            }
                                            )";

        std::string_view fragment_source = R"(#version 330 core
                                              out vec4 FragColor;
                                            void main() {
                                                FragColor = vec4(0.8f, 0.2f, 0.3f, 1.0f);
                                            }
                                            )";

        shader.compile(vertex_source, fragment_source);
        const std::vector<float> vertices = {
            // Positions           // Normals           // UVs
            // Front face
            -0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
            // Back face
            -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
            0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
            0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
            // Top face
            -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
            // Bottom face
            -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
            // Right face
            0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            // Left face
            -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,  1.0f, 0.0f
        };

        const std::vector<unsigned int> indices = {
            0, 1, 2, 2, 3, 0,       // Front
            4, 5, 6, 6, 7, 4,       // Back
            8, 9, 10, 10, 11, 8,    // Top
            12, 13, 14, 14, 15, 12, // Bottom
            16, 17, 18, 18, 19, 16, // Right
            20, 21, 22, 22, 23, 20  // Left
        };
        mesh.create(vertices, indices);
        glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 5.0f);
        glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, 0.0f);

        float aspect_ratio = _context->application->get_aspect_ratio();

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspect_ratio, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(camera_position, camera_target, glm::vec3(0, 1, 0));
        view_projection_matrix = projection * view;
    }

    void on_shutdown() override
    {

    }

    void on_preload() override
    {

    }

    void on_update(float delta_time) override
    {
        if (_context->input->is_key_down(GLFW_KEY_W)) _position.y += _speed * delta_time;
        if (_context->input->is_key_down(GLFW_KEY_S)) _position.y -= _speed * delta_time;
        if (_context->input->is_key_down(GLFW_KEY_D)) _position.x += _speed * delta_time;
        if (_context->input->is_key_down(GLFW_KEY_A)) _position.x -= _speed * delta_time;

        _rotation += _rotation_speed * delta_time;

        model_matrix = glm::mat4(1.0f);
        model_matrix = glm::translate(model_matrix, _position);

        model_matrix = glm::rotate(model_matrix, glm::radians(_rotation), glm::vec3(0.0f, 1.0f, 0.0f));
        model_matrix = glm::rotate(model_matrix, glm::radians(_rotation * 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));

        if(_context->input->is_action_triggered("Quit")) _context->application->quit();
    }

    void on_render() override
    {
        _context->renderer->clear({0.1f, 0.1f, 0.1f, 1.0f});
        _context->renderer->begin_scene(view_projection_matrix);
        _context->renderer->submit(&mesh, &shader, model_matrix);
        _context->renderer->end_scene();
    }
private:
    Context * _context;

    glm::mat4 view_projection_matrix;
    glm::mat4 model_matrix;

    Mesh mesh;
    Shader shader;

    glm::vec3 _position = glm::vec3(0.0f);
    float _rotation = 0.0f;
    float _speed = 5.0f;
    float _rotation_speed = 90.0f;
};

GameApplication * create_gameapp()
{
  return new Game();
}

void destroy_gameapp(GameApplication * game)
{
  delete game;
}
