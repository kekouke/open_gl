#include "VertexAttributeObject.h"
#include <GL/glew.h>

VertexAttributeObject::VertexAttributeObject() {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
}

void VertexAttributeObject::Bind() { glBindVertexArray(id); }

void VertexAttributeObject::EnableVertexAttribArray(GLuint index, GLint size,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLsizei stride,
                                                  const GLvoid* pointer) {
  
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  glEnableVertexAttribArray(index);
}
