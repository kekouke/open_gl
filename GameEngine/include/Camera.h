#pragma once
#include <SFML/Window.hpp>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "mat4.h"

//class Camera {
//public:
//	Camera();
//	glm::mat4 GetViewMatrix();
//	glm::mat4 GetProjectionMatrix();
//	void ReadInput();
//	void MouseInput(sf::Window&);
//
//private:
//	// позиция камеры
//	glm::vec3 positionCamera;
//	glm::vec3 frontCamera;
//	glm::vec3 upCamera;
//	// скорость камеры
//	float speed = 0.05f;
//	// углы эйлера
//	float yaw;
//	float pitch;
//	// координаты мыши
//	float xPos = 800 / 2.0f;
//	float yPos = 600 / 2.0f;
//	// движение мышью в первый раз 
//	bool mouseMove = true;
//};

class Camera {
 public:
  enum class ProjectionMode { ORTHOGRAPHIC, PERSPECTIVE };
  Camera();

  glm::vec3 GetPosition() const;
  void SetPosition(glm::vec3 position);

  glm::vec3 GetFront() const;
  glm::vec3 GetUp() const;


  void Move(glm::vec3);

  const glm::mat4& GetProjectionMatrix() const;
  const glm::mat4& GetViewMatrix() const;
 private:
  glm::mat4 m_viewMatrix;
  glm::mat4 m_projectionMatrix;
  ProjectionMode m_projectionMode;

  glm::vec3 cameraUp;
  glm::vec3 cameraPos;
  glm::vec3 cameraFront;

  float speed;

  float m_fov;
  float m_ratio;
  float m_near;
  float m_far;
};

// float GetFov() const;
// float GetRatio() const;
// float GetNear() const;
// float GetFar() const;
// void SetFov(float p_value);
// void SetRatio(float p_value);
// void SetNear(float p_value);
// void SetFar(float p_value);