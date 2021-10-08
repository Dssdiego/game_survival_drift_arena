////
//// Created by diego on 8/15/21.
////
//
//// This is required to use the stbi lib for loading images
//#define STB_IMAGE_IMPLEMENTATION
//#define GL_GLEXT_PROTOTYPES
//
//#include <SDL_opengl.h>
//#include <stb_image.h>
//#include "texture.h"
//
//void Texture::load(const std::string& imagePath)
//{
//    // REVIEW: Could be the other way around. I have to check
//    // OpenGL loads image from bottom to top while stbi loads image from top to bottom.
//    // This flips the image and corrects it
//    stbi_set_flip_vertically_on_load(true);
//
//    // Load image to texture
//    mData = stbi_load(imagePath.c_str(), &mWidth, &mHeight, &mChannels, 0);
//
//    // Create texture object (handler)
//    glGenTextures(1, &mTexId);
//
//    // Make texture active (bind)
//    glBindTexture(GL_TEXTURE_2D, mTexId);
//
//    // Texture wrapping
//    // REVIEW: I think this is the default behaviour. Probably we don't need to specify!
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    // Texture filtering
//    // NOTE: Only nearest point because I'm only making pixel art games at the moment
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    // Copy image data to texture (upload to GPU)
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mData);
//
//    // Free image from CPU memory (texture is already uploaded to GPU)
//    stbi_image_free(mData);
//}
//
//void Texture::dispose() {
//    // Remove texture from GPU (cleaning)
//    glDeleteTextures(1, &mTexId);
//}
