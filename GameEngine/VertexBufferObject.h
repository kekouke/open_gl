#pragma once

class VertexBufferObject {
 public:
  VertexBufferObject(float vertices[], float size);
  void Bind();

 private:
  unsigned int id;
};
