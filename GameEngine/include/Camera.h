#pragma once
#include <SFML/Window.hpp>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera {
public:
	Camera();
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	void ReadInput();
	void MouseInput(sf::Window&);

private:
	// ������� ������
	glm::vec3 positionCamera;
	glm::vec3 frontCamera;
	glm::vec3 upCamera;
	// �������� ������
	float speed = 0.05f;
	// ���� ������
	float yaw;
	float pitch;
	// ���������� ����
	float xPos = 800 / 2.0f;
	float yPos = 600 / 2.0f;
	// �������� ����� � ������ ��� 
	bool mouseMove = true;
};