////
//// Created by Diego Santos Seabra on 06/07/21.
////
//
//#define GL_GLEXT_PROTOTYPES
//
//#include <SDL_opengl.h>
//#include "triangle.h"
//#include "../shader.h"
//
//Triangle::Triangle()
//{
//    Shader shader = Shader("triangle.vert", "triangle.frag");
//    shader.use();
//
//    float vertices[] = {
//            -0.5f, -0.5f, // Vertex 1 (X, Y)
//            0.5f, -0.5f, // Vertex 2 (X, Y)
//            0.0f,  0.5f  // Vertex 3 (X, Y)
//    };
//
//    // Creating a Vertex Buffer Object
//    glGenBuffers(1, &vbo);
//
//    // Make vbo active
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//    // Copy data to vbo
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // Creating Vertex Array Object
//    glGenVertexArrays(1, &vao);
//
//    // Make vao active
//    glBindVertexArray(vao);
//
//    // Tell OpenGL how to interpret the data
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
//    glEnableVertexAttribArray(0);
//
//    // TODO: Continue here: https://open.gl/drawing
//}
//
//void Triangle::draw()
//{
//    glDrawArrays(GL_TRIANGLES, 0, 3);
//}
//
//Triangle::~Triangle()
//{
//    // Cleanup
//    glDeleteBuffers(1, &vbo);
//    glDeleteVertexArrays(1, &vao);
//}
