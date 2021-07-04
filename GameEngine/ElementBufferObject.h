#pragma once

#include <GL/glew.h>

class ElementBufferObject {
 public:
  ElementBufferObject(unsigned int indices[], unsigned int size);
  void Bind();

 private:
  unsigned int id_;
};
