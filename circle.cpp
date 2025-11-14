#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <learnopengl/shader_m.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

class Circle {
public:
    Circle(glm::vec3 center, float radius, glm::vec3 c, int segments = 36) {
        color = c;
        model = glm::mat4(1.0f);

        vertices.push_back(center); 
        for (int i = 0; i <= segments; i++) {
            float angle = i * 2.0f * glm::pi<float>() / segments;
            float x = center.x + radius * cos(angle);
            float y = center.y + radius * sin(angle);
            vertices.push_back(glm::vec3(x, y, center.z));
        }

        // Setup VAO & VBO
        GLuint VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void transformation(glm::mat4 t) {
        model = t;
    }

    void draw(Shader& shader) {
        shader.setVec3("objectColor", color);
        shader.setMat4("model", model);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
        glBindVertexArray(0);
    }

    void deleteBuffers() {
        glDeleteVertexArrays(1, &VAO);
    }

private:
    std::vector<glm::vec3> vertices;
    glm::vec3 color;
    glm::mat4 model;
    GLuint VAO;
    Circle();
};