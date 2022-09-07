//
// Created by beyley on 9/7/22.
//

#include <glad/glad.h>
#include <string.h>
#include <malloc.h>

#ifndef CGAMEENGINE_SHADER_H
#define CGAMEENGINE_SHADER_H

typedef enum {
    vertex,
    fragment
} shader_type;

typedef struct {
    uint32_t name;
    shader_type type;
} shader;

typedef struct {
    uint32_t name;
    shader vtx;
    shader frg;
} program;

shader create_shader(char* src, shader_type type) {
    GLenum gl_type;

    switch (type) {
        case vertex:
            gl_type = GL_VERTEX_SHADER;
            break;
        case fragment:
            gl_type = GL_FRAGMENT_SHADER;
            break;
    }

    shader shader;

    shader.name = glCreateShader(gl_type);
    shader.type = type;

    uint32_t len = strlen(src);

    glShaderSource(shader.name, 1, (const GLchar *const *) src, (GLint const*)&len);

    glCompileShader(shader.name);

    int32_t status;
    glGetShaderiv(shader.name, GL_COMPILE_STATUS, &status);

    if(status == GL_FALSE) {
        const int buf_size = 256;
        char* info_log = malloc(buf_size);

        int32_t length;

        glGetShaderInfoLog(shader.name, buf_size, &length, info_log);

        printf("Failed to compile shader! Info log: %s", info_log);

        free(info_log);
    }

    return shader;
}

program create_program(char* vtx, char* frg) {
    program program;

    program.name = glCreateProgram();

    program.vtx = create_shader(vtx, vertex);
    program.frg = create_shader(frg, fragment);

    glAttachShader(program.name, program.vtx.name);
    glAttachShader(program.name, program.frg.name);

    glLinkProgram(program.name);

    int32_t status;
    glGetProgramiv(program.name, GL_LINK_STATUS, &status);

    if(status == GL_FALSE) {
        const int32_t buf_size = 256;
        char* info_log = malloc(buf_size);

        int32_t length;
        glGetProgramInfoLog(program.name, 1, &length, info_log);

        printf("Failed to link shader! log: %s", info_log);

        free(info_log);
    }

    return program;
}

#endif //CGAMEENGINE_SHADER_H
