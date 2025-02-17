cmake_minimum_required(VERSION 3.5.0)
project(learn_shaders VERSION 0.1.0 LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(
    learn_shaders
    src/main.cpp
    src/glad/glad.c
    src/glad/glad.h
    src/stb/stb_image.h 
    src/stb/stb.cpp
    src/shaders/fragmentShader.frag.glsl
    src/shaders/vertexShader.vert.glsl
    src/classes/Classes.h
    src/classes/Shader.h
    src/classes/Shader.cpp
    src/classes/Shape.h
    src/classes/Shape.cpp
    src/classes/debug.cpp
    src/classes/debug.h
    src/classes/ElementBufferObject.h 
    src/classes/ElementBufferObject.cpp
    src/classes/VertexArrayObject.h 
    src/classes/VertexArrayObject.cpp
    src/classes/VertexBufferObject.h 
    src/classes/VertexBufferObject.cpp
    src/classes/Texture.h 
    src/classes/Texture.cpp
    )

target_link_libraries(learn_shaders glfw OpenGL::GL)
