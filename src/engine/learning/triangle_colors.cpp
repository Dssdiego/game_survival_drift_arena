//
// Created by diego on 7/8/21.
//

#define GL_GLEXT_PROTOTYPES

#include "triangle_colors.h"

// Creates a triangle with vertex colors
TriangleColors::TriangleColors()
{
    // Create, compile and use shader
    mShader = Shader("triangle_colors.vert", "triangle_colors.frag");
    mShader.use();

    float vertices[] = {
        //  Pos X, Pos Y, Red, Green, Blue
            -0.5f, -0.5f, 1.0, 0.0, 0.0,
             0.5f, -0.5f, 0.0, 1.0, 0.0,
             0.0f,  0.5f, 0.0, 0.0, 1.0
    };

    // Creating a Vertex Buffer Object
    glGenBuffers(1, &vbo);

    // Make vbo active
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Copy data to vbo
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Creating Vertex Array Object
    glGenVertexArrays(1, &vao);

    // Make vao active
    glBindVertexArray(vao);

    // Tell OpenGL how to interpret the data

    // positions (x,y)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);

    // colors (r,g,b)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (2 * sizeof(float)));
}

void TriangleColors::draw()
{
    // Draws the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Makes the triangle wireframe'd or not
    if(mIsWireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void TriangleColors::cleanUp()
{
    // Cleanup
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    mShader.cleanUp();
}
