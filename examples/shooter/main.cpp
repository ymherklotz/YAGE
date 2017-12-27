#include <yage/yage.h>

#include "glad/glad.h"

#include <iostream>

using std::cout;

int main(int argc, char **argv)
{
    cout << "Starting Shooter example...\n";

    yage::Window window;
    window.create("Shooter example", 800, 600);

    yage::Shader shader("examples/resources/colourshader.vert",
                        "examples/resources/colourshader.frag");

    GLfloat vertices[] = {
        0.0f,  0.5f,  1.f, 0.f, 0.f, // Vertex 1 (X, Y, R, G, B)
        0.5f,  -0.5f, 0.f, 1.f, 0.f, // Vertex 2 (X, Y, R, G, B)
        -0.5f, -0.5f, 0.f, 0.f, 1.f, // Vertex 3 (X, Y, R, G, B)
    };

    // create vertex array
    GLuint rect_vao, rect_vbo;

    // bind vertex array object
    glGenVertexArrays(1, &rect_vao);
    glBindVertexArray(rect_vao);

    // bind vertex buffer object
    glGenBuffers(1, &rect_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, rect_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    shader.use();

    // enable vertex attribute arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // set the vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                          (void *)(2 * sizeof(GLfloat)));

    while (!window.shouldClose()) {
        window.pollEvents();
        window.clearBuffer();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffer();
    }

    glDeleteBuffers(1, &rect_vbo);

    glDeleteVertexArrays(1, &rect_vao);
}
