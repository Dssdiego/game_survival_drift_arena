//
// Created by dss-d on 22/09/2021.
//

#include "aseprite.h"
#include <iostream>
#include <fstream>
#include <vector>

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef int16_t SHORT;
typedef uint32_t DWORD;

struct AseHeader {
    DWORD fileSize;
    WORD magicNumber;
    WORD frames;
    WORD width;
    WORD height;
    WORD colorDepth;
    DWORD flags;
//    WORD speed; // NOTE: Deprecated
    DWORD skip1; // NOTE: Set be 0
    DWORD skip2; // NOTE: Set be 0
    BYTE paletteEntryIndex;
    BYTE skip3[3]; // Skip these bytes
    WORD numberOfColors;
    BYTE pixelWidth;
    BYTE pixelHeight;
    SHORT gridX;
    SHORT gridY;
    WORD gridWidth;
    WORD gridHeight;
    BYTE future[84];
};

struct AseFrame {
    DWORD size;
    WORD magicNumber;
    WORD numberOfChunksOld;
    WORD duration;
    BYTE future[2];
    DWORD numberOfChunksNew;
};

struct AseChunk {
    DWORD size;
    WORD type;
    BYTE data[];
};

void Aseprite::read(std::string filename)
{
    std::ifstream aseFile(filename.c_str(), std::ios::binary);

    AseHeader header;
    aseFile.read(reinterpret_cast<char *>(&header), sizeof(header));

    // TODO: Jump header (128 bytes)
    // TODO: Read frames

    std::cout << "Reading aseprite file..." << std::endl;

    // close the file
    aseFile.close();
}
