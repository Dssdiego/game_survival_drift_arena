//
// Created by Diego Santos Seabra on 10/07/21.
//

#if UNIX || __APPLE__
#define GL_GLEXT_PROTOTYPES
#endif

//#define STB_IMAGE_IMPLEMENTATION

#include "quad_textured.h"
#include "stb_image.h"

QuadTextured::QuadTextured()
{
    // Image configuration
    std::string imgName = "assets/sprites/car.png";
    int imgWidth, imgHeight, imgChannels;

    // REVIEW: Could be the other way around. I have to check
    // OpenGL loads image from bottom to top while stbi loads image from top to bottom.
    // This flips and corrects it
    stbi_set_flip_vertically_on_load(true);

    // Load image to texture
    unsigned char *imgData = stbi_load(imgName.c_str(),&imgWidth, &imgHeight, &imgChannels, 0);

    // Create a texture object (handler)
    glGenTextures(1, &texture);

    // Make texture active (bind)
    glBindTexture(GL_TEXTURE_2D, texture);

    // Texture wrapping
    // REVIEW: I think this is the default behaviour. Probably we don't need to specify!
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // best for pixel art
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // best for pixel art

    // Copy image data to texture (upload to GPU)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

    // Free image from CPU memory (texture is already uploaded to GPU)
    stbi_image_free(imgData);

    // Create, compile and use shader
    mShader = Shader("quad_textured.vert", "quad_textured.frag");
    mShader.use();

    // Define the vertices array
    float vertices[] = {
         // Pos X, Pos Y, Tex Coords
            0.5f,  0.5f,  1.0f, 1.0f, // top right
            0.5f, -0.5f,  1.0f, 0.0f, // bottom right
           -0.5f, -0.5f,  0.0f, 0.0f, // bottom left
           -0.5f,  0.5f,  0.0f, 1.0f  // top left
    };

    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first triangle
            1, 2, 3   // second triangle
    };

    // Creating a Vertex Buffer Object
    glGenBuffers(1, &vbo);

    // Make vbo active (bind)
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Copy data to vbo
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Creating a Element Buffer Object
    glGenBuffers(1, &ebo);

    // Make ebo active (bind)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    // Copy data to ebo
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Creating Vertex Array Object
    glGenVertexArrays(1, &vao);

    // Make vao active
    glBindVertexArray(vao);

    // Tell OpenGL how to interpret the data

    // positions (x,y)
    GLint idxPosition = glGetAttribLocation(mShader.getProgram(), "aPos");
    glEnableVertexAttribArray(idxPosition);
    glVertexAttribPointer(idxPosition, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);

    // texture coordinates (s,t)
    GLint idxTexCoords = glGetAttribLocation(mShader.getProgram(), "aTexCoords");
    glEnableVertexAttribArray(idxTexCoords);
    glVertexAttribPointer(idxTexCoords, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) (2 * sizeof(float)));
}

void QuadTextured::draw()
{
    // Draws the quad (two triangles)
    mShader.use();
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void QuadTextured::cleanUp()
{
    // Cleanup
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteTextures(1, &texture);
    glDeleteVertexArrays(1, &vao);

    mShader.cleanUp();
}
