#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "GL/glew.h"
#include "glm/glm.hpp"

class Shader {
 public:
  Shader(const std::string vertex_file_path, const std::string fragment_file_path);

  void Use();
  void SetMat4(std::string name, const glm::mat4& data);
  void SetInt(const std::string& name, int value) const;

 private:
  unsigned int ID;

  GLuint LoadShaders(const std::string vertex_file_path,
                     const std::string fragment_file_path);
};