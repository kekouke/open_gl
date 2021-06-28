#include "VertexBufferObject.h"
#include <GL/glew.h>

VertexBufferObject::VertexBufferObject(float vertices[], float size) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * size, vertices, GL_STATIC_DRAW);
}

void VertexBufferObject::Bind() { glBindBuffer(GL_ARRAY_BUFFER, id); }
