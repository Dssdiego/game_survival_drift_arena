//
// Created by diego on 8/15/21.
//

#pragma once

#include <string>

enum ImageType {
    PNG,
    JPG
};

class Texture
{
public:
    void load(const std::string& imageFileName);
    void dispose();

//    inline unsigned int getTexture() const { return mTexId; }
private:
    unsigned int mTexId;
    unsigned char *mData;
    int mWidth, mHeight, mChannels;
};

