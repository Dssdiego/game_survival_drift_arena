//
// Created by Diego Santos Seabra on 27/06/21.
//

#define GL_GLEXT_PROTOTYPES

#include "shader.h"
#include "log.h"
#include <iostream>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include <fstream>
#include <vector>

Shader::Shader()
{
    // Control variables
    GLint isCompiled = 0;
    GLint isLinked = 0;

    //////////////
    /// Vertex ///
    //////////////

    // Vertex source code
    std::fstream vertexSrcFile("assets/shaders/vertex.glsl");
    std::string vertexSrc( (std::istreambuf_iterator<char>(vertexSrcFile) ),
                             (std::istreambuf_iterator<char>()    ) );

    // Create empty vertex shader handle
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Send vertex shader source code to GL
    const GLchar* vertexGlSrc = vertexSrc.c_str();
    glShaderSource(vertexShader, 1, &vertexGlSrc, nullptr);

    // Compile vertex shader
    glCompileShader(vertexShader);

    // Check for compilation errors
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

    // If the vertex shader didn't compile...
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

        glDeleteShader(vertexShader);

        Log::error("Error compiling vertex shader");

        return;
    }

    ////////////////
    /// Fragment ///
    ////////////////

    // Read fragment GLSL file
    std::fstream fragmentSrcFile("assets/shaders/fragment.glsl");
    std::string fragmentSrc( (std::istreambuf_iterator<char>(fragmentSrcFile) ),
                         (std::istreambuf_iterator<char>()    ) );

    // Create empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send fragment shader source code to GL
    const GLchar* fragmentGlSrc = fragmentSrc.c_str();
    glShaderSource(fragmentShader, 1, &fragmentGlSrc, nullptr);

    // Compile fragment shader
    glCompileShader(fragmentShader);

    // Check for errors on fragment shader compilation
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

    // If the fragment shader didn't compile...
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

        // Don't leak shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        Log::error("Error compiling fragment shader");

        return;
    }

    // If the code executed till this point,
    // it means both our shaders compiled successfully

    // Creating a program shader object
    GLuint program = glCreateProgram();

    // Attach both our shaders to the program
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    Log::info("Linking vertex and fragment shaders to program");

    // Link our program
    glLinkProgram(program);

    // Check for errors when linking the shader
    glGetProgramiv(program, GL_LINK_STATUS, (int *) &isLinked);

    // If the shader link wasn't successful
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        std::cout << "Shader link error: " << &infoLog[0] << std::endl;

        // We don't need our program anymore
        glDeleteProgram(program);

        // Don't leak shaders...
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        Log::error("Error linking shader program");

        return;
    }

    // Dettach our shaders (we don't need them anymore)
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    // Use our shader
    // FIXME: This should be here? Or should be elsewhere?
    glUseProgram(program);
}
