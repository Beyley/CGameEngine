#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "types.h"
#include "shader.h"

char* vtx =
    "#version 450\n"

    "#extension GL_NV_gpu_shader5 : require\n"
    "#extension GL_ARB_gpu_shader_int64 : require\n"

    "void main() {"
        ""
    "}";

char* frg =
        "#version 450\n";

int main() {
    glfwSetErrorCallback(&error_callback);

    if(!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "CGameEngine", NULL, NULL);
    if(!window)
        return -1;

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(gl_callback, NULL);

    //Enable vsync
    glfwSwapInterval(1);

    int width, height;

    while(!glfwWindowShouldClose(window)) {
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
