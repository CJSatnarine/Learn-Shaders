#include "Shape.h"
#include "../glad/glad.h"
#include "ElementBufferObject.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

Shape::Shape(float vert[], unsigned int vertCount, unsigned int indi[],
             unsigned int indiCount)
    : VBO(vert, vertCount), EBO(indi, indiCount), indi_count(indiCount) {
    VAO.Bind();
    VBO.Bind();
    EBO.Bind();

    VAO.LinkVBO(VBO, 0);
}

void Shape::Render(Shader &shader) {
    shader.Activate();
    VAO.Bind();
    glDrawElements(GL_TRIANGLES, indi_count, GL_UNSIGNED_INT, 0);
}

void Shape::Delete() {
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
}
