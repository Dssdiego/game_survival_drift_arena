//
// Created by Diego Santos Seabra on 27/06/21.
//

#define GL_GLEXT_PROTOTYPES

#include "shader.h"
#include <iostream>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include <fstream>

Shader::Shader()
{
    // Control variables
    GLint isCompiled = 0;

    //////////////
    /// Vertex ///
    //////////////

    // Vertex source code
//    std::string vertexSrc = "#version 330 core"
//                            ""
//                            "void main() {"
//                            ""
//                            "}"
//                            "gl_Position = ;";

    // Create empty vertex shader handle
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Send vertex shader source code to GL
//    const GLchar* vertexGlSrc = vertexSrc.c_str();
//    glShaderSource(vertexShader, 1, &vertexGlSrc, nullptr);

    // Compile vertex shader
//    glCompileShader(vertexShader);

    // Check for compilation errors
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

    ////////////////
    /// Fragment ///
    ////////////////

    // Read fragment GLSL file
    std::fstream fragmentSrcFile("assets/shaders/fragment.glsl");
    std::string fragmentSrc( (std::istreambuf_iterator<char>(fragmentSrcFile) ),
                         (std::istreambuf_iterator<char>()    ) );

    // Create empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send vertex shader source code to GL
    const GLchar* fragmentGlSrc = fragmentSrc.c_str();
    glShaderSource(fragmentShader, 1, &fragmentGlSrc, nullptr);

    // Compile vertex shader
    glCompileShader(fragmentShader);

}
