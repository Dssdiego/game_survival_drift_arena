////
//// Created by Diego Santos Seabra on 27/06/21.
////
//
//#include "text.h"
//
//void Text::init()
//{
//    // Text vertex shader source
//    quadVertexSource =
//            "attribute vec4 position;                                   \n"
//            "varying vec2 texCoord;                                     \n"
//            "uniform vec2 viewport;                                     \n"
//            "uniform vec2 textSize;                                     \n"
//            "uniform vec2 texSize;                                      \n"
//            "void main()                                                \n"
//            "{                                                          \n"
//            "    gl_Position = vec4(position.xyz, 1.0);                 \n"
//            "    gl_Position.x *= textSize.x;                           \n"
//            "    gl_Position.y *= textSize.y;                           \n"
//            "                                                           \n"
//            "    // Translate to lower left viewport                    \n"
//            "    gl_Position.x -= viewport.x / 2.0;                     \n"
//            "    gl_Position.y -= viewport.y / 2.0;                     \n"
//            "                                                           \n"
//            "    // Ortho projection                                    \n"
//            "    gl_Position.x += 1.0;                                  \n"
//            "    gl_Position.x *= 2.0 / viewport.x;                     \n"
//            "    gl_Position.y += 1.0;                                  \n"
//            "    gl_Position.y *= 2.0 / viewport.y;                     \n"
//            "                                                           \n"
//            "    // Text subrectangle from overall texture              \n"
//            "    texCoord.x = position.x * textSize.x / texSize.x;      \n"
//            "    texCoord.y = -position.y * textSize.y / texSize.y;     \n"
//            "}                                                          \n";
//
//    // Text fragment shader source
//    quadFragmentSource =
//            "precision mediump float;                                   \n"
//            "varying vec2 texCoord;                                     \n"
//            "uniform sampler2D texSampler;                              \n"
//            "void main()                                                \n"
//            "{                                                          \n"
//            "    gl_FragColor = texture2D(texSampler, texCoord);        \n"
//            "}                                                          \n";
//
//
//}
