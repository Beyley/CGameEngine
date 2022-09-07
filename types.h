//
// Created by beyley on 9/6/22.
//

#ifndef CGAMEENGINE_TYPES_H
#define CGAMEENGINE_TYPES_H

#include <math.h>
#include <bits/stdint-uintn.h>

#include <stdio.h>
#include <glad/glad.h>

void error_callback(int error_code, const char* message) {
    printf("Error code: %d\nMessage: %s\n", error_code, message);
}

void gl_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam) {
    printf("GL Debug Callback: %s", message);
}

typedef struct {
    float x;
    float y;
} vector_2;

typedef struct {
    float r;
    float g;
    float b;
    float a;
} color;

typedef struct {
    vector_2 position;
    vector_2 texture_position;
    uint64_t texture_handle;
    color    color;
} Vertex;

#endif //CGAMEENGINE_TYPES_H
