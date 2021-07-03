#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "include/mat4.h"

class Shader {
 public:
  Shader(const std::string vertex_file_path, const std::string fragment_file_path);
  void Use();
  void SetMat4(std::string name, const glm::mat4& data);
  void SetMat4(const std::string& name, const mat4& data);
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;
  void SetVec3(const std::string& name, const glm::vec3& value) const;
  void SetVec3(const std::string& name, float x, float y, float z) const;
  void SetVec3(const std::string& name, const vec3& value) const;
  int get_shader_id() const { return id_;}

 private:
  unsigned int id_;

  GLuint LoadShaders(const std::string vertex_file_path,
                     const std::string fragment_file_path);

  glm::mat4 mat4_to_glm_mat4(const mat4& target);
};