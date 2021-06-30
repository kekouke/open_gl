#include "include/Camera.h"


Camera::Camera(glm::vec3 position, float fov)
    : position(position), fov(fov), rotation(1.0f) {
  updateVectors();
}

glm::mat4 Camera::getProjection() { 
  return glm::perspective(fov, 800.0f / 600.0f, 0.1f, 100.0f); // TODO
}

glm::mat4 Camera::getView() { 
  return glm::lookAt(position, position + front, up);
}

glm::vec3 Camera::getFront() const { return front; }

glm::vec3 Camera::getUp() const { return up; }

glm::vec3 Camera::getPosition() const { return position; }

void Camera::rotate(float x, float y, float z) {
  this->rotation = glm::mat4(1.0f);

  rotation = glm::rotate(rotation, z, glm::vec3(0, 0, 1));
  rotation = glm::rotate(rotation, y, glm::vec3(0, 1, 0));
  rotation = glm::rotate(rotation, x, glm::vec3(1, 0, 0));

  updateVectors();
}

void Camera::translate(glm::vec3 position) { this->position += position; }

void Camera::updateVectors() {
  front = glm::vec3(rotation * glm::vec4(0, 0, -1, 1));
  up = glm::vec3(rotation * glm::vec4(0, 1, 0, 1));
  right = glm::vec3(rotation * glm::vec4(-1, 0, 0, 1));
}
