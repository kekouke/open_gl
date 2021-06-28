#pragma once

#include <string>

class Texture {
 public:
  Texture(const char* path);
  unsigned int getTextureId() const;
  void Bind();

 private:
  unsigned int id;
};
