#include "ElementBufferObject.h"

ElementBufferObject::ElementBufferObject(unsigned int indices[], unsigned int size) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * size, indices, GL_STATIC_DRAW);
}

void ElementBufferObject::Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_); }
