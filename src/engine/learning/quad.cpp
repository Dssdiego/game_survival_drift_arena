//
// Created by Diego Santos Seabra on 09/07/21.
//

#if UNIX || __APPLE__
#define GL_GLEXT_PROTOTYPES
#endif

#include "quad.h"

Quad::Quad()
{
    // Create, compile and use shader
    mShader = Shader("quad.vert", "quad.frag");
    mShader.use();

    // Define the vertices array
    float vertices[] = {
         // Pos X, Pos Y, Red, Green, Blue
             1.0f,  1.0f, 0.0f, 0.0f, 0.0f, // top right
             1.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom right
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom left
            -1.0f,  1.0f, 0.0f, 0.0f, 0.0f  // top left
    };

    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,   // first triangle
            1, 2, 3   // second triangle
    };

    // Creating a Vertex Buffer Object
    glGenBuffers(1, &vbo);

    // Make vbo active (bind)
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Copy data to vbo
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    // Creating a Element Buffer Object
    glGenBuffers(1, &ebo);

    // Make ebo active (bind)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    // Copy data to ebo
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

    // Creating Vertex Array Object
    glGenVertexArrays(1, &vao);

    // Make vao active
    glBindVertexArray(vao);

    // Tell OpenGL how to interpret the data

    // positions (x,y)
    GLint idxPosition = glGetAttribLocation(mShader.getProgram(), "aPos");
    glEnableVertexAttribArray(idxPosition);
    glVertexAttribPointer(idxPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);

    // colors (x,y)
    GLint idxColors = glGetAttribLocation(mShader.getProgram(), "aColor");
    glEnableVertexAttribArray(idxColors);
    glVertexAttribPointer(idxColors, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (2 * sizeof(float)));

    // alpha (uniform)
    GLint idxAlpha = glGetUniformLocation(mShader.getProgram(), "alpha");
    glUniform1f(idxAlpha, 1.0f);
}

void Quad::draw()
{
    // Draws the quad (two triangles)
    mShader.use();

    // Make modifications (?)
//    if(alpha > 0.0f)
    alpha += 0.0001f;

//    if(alpha < 0.0f)
//        alpha += 0.0001f;

    GLint idxAlpha = glGetUniformLocation(mShader.getProgram(), "alpha");
    glUniform1f(idxAlpha, alpha);

    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    // wireframe mode
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Quad::cleanUp()
{
    // Cleanup
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    mShader.cleanUp();
}
