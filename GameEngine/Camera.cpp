#include "include/Camera.h"


Camera::Camera(vec3 position, float fov)
    : position(position), fov(fov), rotation(1.0f) {
  updateVectors();
}

mat4 Camera::getProjection() { 
  return mat4::perspective(fov, 800.0f / 600.0f, 0.1f, 100.0f);
}

mat4 Camera::getView() { 
  return mat4::look_at(position, position + front, up);
}

vec3 Camera::getFront() const { return front; }

vec3 Camera::getUp() const { return up; }

vec3 Camera::getPosition() const { return position; }

void Camera::rotate(float x, float y, float z) {
  this->rotation = mat4(1.0f);

  rotation = rotation * mat4::rotation_matrix(z, vec3(0, 0, 1));
  rotation = rotation * mat4::rotation_matrix(y, vec3(0, 1, 0));
  rotation = rotation * mat4::rotation_matrix(x, vec3(1, 0, 0));

  updateVectors();
}

void Camera::translate(vec3 position) {
  this->position = this->position + position;
}

mat4 Camera::get_view_mat3() { 
  mat4 res = getView();
  res[3][0] = 0;
  res[3][1] = 0;
  res[3][2] = 0;
  res[3][3] = 0;

  return res;
}

void Camera::updateVectors() {
  front = vec3(rotation * vec4(0, 0, -1, 1));
  up = vec3(rotation * vec4(0, 1, 0, 1));
  right = vec3(rotation * vec4(-1, 0, 0, 1));
}
