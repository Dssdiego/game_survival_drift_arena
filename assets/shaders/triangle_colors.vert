#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec3 aColor;

out vec4 colorFromVert;

void main()
{
    // Since we are drawing a 2D triangle, Z position is always 0!
    gl_Position = vec4(aPos, 0.0, 1.0);

    // Passing color to the fragment shader
    colorFromVert = vec4(aColor.rgb, 1.0);
}