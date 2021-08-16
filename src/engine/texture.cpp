//
// Created by diego on 8/15/21.
//

// This is required to use the stbi lib for loading images
#define STB_IMAGE_IMPLEMENTATION
#define GL_GLEXT_PROTOTYPES

#include <SDL_opengl.h>
#include <stb_image.h>
#include "texture.h"

void Texture::load(const std::string& imageFileName)
{
    // REVIEW: Could be the other way around. I have to check
    // OpenGL loads image from bottom to top while stbi loads image from top to bottom.
    // This flips the image and corrects it
    stbi_set_flip_vertically_on_load(true);

    // Load image to texture
    mData = stbi_load(imageFileName.c_str(), &mWidth, &mHeight, &mChannels, 0);

    // Create texture object (handler)
    glGenTextures(1, &mTexId);

    // Make texture active (bind)
    glBindTexture(GL_TEXTURE_2D, mTexId);
}
