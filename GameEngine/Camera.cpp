#include "include/Camera.h"

Camera::Camera() {
  cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
  cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

  m_viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront,
                  cameraUp);

  m_projectionMatrix =
      glm::perspective<float>(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);
}

glm::vec3 Camera::GetPosition() const { return cameraPos; }

void Camera::SetPosition(glm::vec3 position) { 
  cameraPos = position;
  m_viewMatrix = glm::lookAt(cameraPos, cameraFront, cameraUp);
}

glm::vec3 Camera::GetUp() const { return cameraUp; }

glm::vec3 Camera::GetFront() const { return cameraFront; }



const glm::mat4& Camera::GetProjectionMatrix() const {
  return m_projectionMatrix;
}

const glm::mat4& Camera::GetViewMatrix() const {
  return m_viewMatrix;
}

void Camera::Move(glm::vec3 move) {
  cameraPos += move;
  m_viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}