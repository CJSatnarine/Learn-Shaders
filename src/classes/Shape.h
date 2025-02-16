#ifndef SHAPE_H
#define SHAPE_H

#include "../glad/glad.h"
#include "ElementBufferObject.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

class Shape {
  public:
    VertexArrayObject VAO;
    VertexBufferObject VBO;
    ElementBufferObject EBO;

    unsigned indi_count;

    Shape(float vert[], unsigned int vertCount, unsigned int indi[],
          unsigned int indiCount);

    virtual void Render(Shader &shader);

    virtual void Delete();
};

#endif
