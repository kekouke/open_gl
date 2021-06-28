#pragma once
#include <GL/glew.h>

class VertexAttributeObject {
 public:
  VertexAttributeObject();
  void Bind();
  void EnableVertexAttribArray(GLuint index, GLint size, GLenum type,
                             GLboolean normalized, GLsizei stride,
                             const GLvoid* pointer);

 private:
  unsigned int id;
};
