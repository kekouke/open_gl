#pragma once
#include <SFML/Window.hpp>
#include "vec3.h"
#include "mat4.h"

class Camera {
 public:
  Camera(vec3 position, float fov);
  mat4 getProjection();
  mat4 getView();
  vec3 getFront() const;
  vec3 getUp() const;
  vec3 getPosition() const;
  void rotate(float x, float y, float z);
  void translate(vec3 position);
  mat4 get_view_mat3();


 private:
  void updateVectors();
  
  vec3 front;
  vec3 right;
  vec3 up;
  vec3 position;
  mat4 rotation;
  float fov;
};