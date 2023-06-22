#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 transformation;

out vec4 color;

void main() {
    gl_Position = transformation * vec4(aPos, 1.0);
    color = vec4(aColor, 1.0);
}