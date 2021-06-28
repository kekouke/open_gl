#pragma once
#include <SFML/Window.hpp>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "mat4.h"

class Camera {
 public:
  Camera(glm::vec3 position, float fov);
  glm::mat4 getProjection();
  glm::mat4 getView();
  glm::vec3 getFront() const;
  glm::vec3 getUp() const;
  void rotate(float x, float y, float z);
  void translate(glm::vec3 position);

 private:
  void updateVectors();
  
  glm::vec3 front;
  glm::vec3 right;
  glm::vec3 up;
  glm::vec3 position;
  glm::mat4 rotation;
  float fov;
};