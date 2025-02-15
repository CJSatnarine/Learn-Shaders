/*
 * This template contains code for creating an empty
 * window in OpenGL.
 */

#include "classes/ElementBufferObject.h"
#include "classes/VertexArrayObject.h"
#include "classes/VertexBufferObject.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "classes/Classes.h"

// Prototypes.
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// Constants.
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

float vertices[] = {
     1.0f,  1.0f, 0.0f,  // top right
     1.0f, -1.0f, 0.0f,  // bottom right
    -1.0f, -1.0f, 0.0f,  // bottom left
    -1.0f,  1.0f, 0.0f   // top left 
};

unsigned int indices[] = {
    0, 1, 3, // first Triangle
    1, 2, 3  // second Triangle
};

int main(void) {
    // Initialisation and configuration.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window.
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                          "Learn Shaders", NULL, NULL);
    if (window == NULL) {
        LogInfo("Failed to create GLFW window.");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LogInfo("Failed to initialise GLAD.");
        return -1;
    }

    // Shader stuff. 
    Shader shader("../src/shaders/vertexShader.vert.glsl", "../src/shaders/fragmentShader.frag.glsl");

    VertexArrayObject VAO;
    VAO.Bind();
    VertexBufferObject VBO(vertices, sizeof(vertices));
    VBO.Bind();
    ElementBufferObject EBO(indices, sizeof(indices));
    EBO.Bind();

    VAO.LinkVBO(VBO, 0);

    // while loop goes here.
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
    shader.Delete();
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
