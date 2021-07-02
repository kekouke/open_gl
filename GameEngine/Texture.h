#pragma once

#include <string>

class Texture {
 public:
  Texture(const char* path);
  unsigned int getTextureId() const;
  void Bind(int layout = -1);

 private:
  unsigned int id;
};
