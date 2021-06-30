#pragma once

#include <GL/glew.h>
#include <iostream>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"
#include "include/Camera.h"
#include "include/Shader.h"
#include "stb_image.h"
#include "Game.h"
#include "Texture.h"
#include "VertexBufferObject.h"
#include "VertexAttributeObject.h"

bool mouseFirst = true;
GLfloat yaw = 0.0f;
GLfloat pitch = 0.0f;
GLfloat lastX = 800 / 2.0;
GLfloat lastY = 600 / 2.0;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

void mouse_callback(float, float);

int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "First Window",
                          sf::Style::Titlebar | sf::Style::Close, settings);

  //Game game;

  //while (game.is_running()) {
  //  game.update();
  //  game.draw();
  //}

   //window.setMouseCursorVisible(false);

   //window.setMouseCursorGrabbed(true);

  glewExperimental = GL_TRUE;
  glEnable(GL_DEPTH_TEST);

  if (GLEW_OK != glewInit()) {
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.fs");
  Shader cubeShader("res/shaders/e4.vs", "res/shaders/e4.fs");

  Camera camera(glm::vec3(0, 0, 3), glm::radians(70.0f));

float vertices[] = {
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,
      0.5f,  -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,
      0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
      0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,

      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,
      0.5f,  -0.5f, 0.5f, 0.0f,  0.0f,  1.0f,
      0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
      0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
      -0.5f, 0.5f,  0.5f, 0.0f,  0.0f,  1.0f,
      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,

      -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,
      -0.5f, 0.5f,  -0.5f, -1.0f, 0.0f,  0.0f,
      -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,
      -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,
      -0.5f, -0.5f, 0.5f, -1.0f, 0.0f,  0.0f,
      -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,

      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
      0.5f,  0.5f,  -0.5f, 1.0f,  0.0f,  0.0f,
      0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
      0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
      0.5f,  -0.5f, 0.5f, 1.0f,  0.0f,  0.0f,
      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

      -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,
      0.5f,  -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,
      0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,
      0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,
      -0.5f, -0.5f, 0.5f, 0.0f,  -1.0f, 0.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,

      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,
      0.5f,  0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,
      0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
      0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
      -0.5f, 0.5f,  0.5f, 0.0f,  1.0f,  0.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f};

  VertexAttributeObject cubeVAO;
  VertexBufferObject VBO(vertices, sizeof(vertices) / sizeof(float));

  cubeVAO.Bind();
  cubeVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  cubeVAO.EnableVertexAttribArray(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

  VertexAttributeObject lightVAO;
  lightVAO.Bind();
  VBO.Bind();
  lightVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

  float cameraSpeed = 0.03f;

  bool isGo = true;
  while (isGo) {
    sf::Event windowEvent;

    auto mousePos = sf::Mouse::getPosition();

    mouse_callback(mousePos.x, mousePos.y);

    camera.rotate(glm::radians(pitch), -glm::radians(yaw), 0);

    while (window.pollEvent(windowEvent)) {
      switch (windowEvent.type) {
        case sf::Event::Closed:
          isGo = false;
          break;
        case sf::Event::KeyPressed:
          if (windowEvent.key.code == sf::Keyboard::W) {
            camera.translate(camera.getFront() * cameraSpeed);
          }
          if (windowEvent.key.code == sf::Keyboard::S) {
            camera.translate(-camera.getFront() * cameraSpeed);
          }
          if (windowEvent.key.code == sf::Keyboard::A) {
            camera.translate(-glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * cameraSpeed);
          }
          if (windowEvent.key.code == sf::Keyboard::D) {
            camera.translate(glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * cameraSpeed);
          }
          break;
        default:
          break;
      }
    }


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cubeShader.Use();
    cubeShader.SetVec3("objectColor", 1.0f, 0.5f, 0.31f);
    cubeShader.SetVec3("lightColor", 1.0f, 1.0f, 1.0f);
    cubeShader.SetVec3("lightPos", lightPos);
    cubeShader.SetVec3("viewPos", camera.getPosition());
   

    glm::mat4 model = glm::mat4(1.0f);
    auto view = camera.getView();
    auto prj = camera.getProjection();

    cubeShader.SetMat4("model", model);
    cubeShader.SetMat4("view", view);
    cubeShader.SetMat4("projection", prj);

    cubeVAO.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 36);


    lampShader.Use();
    lampShader.SetMat4("projection", prj);
    lampShader.SetMat4("view", view);
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    lampShader.SetMat4("model", model);

    lightVAO.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 36);

    window.display();
  }

  window.close();

  return 0;
}

void mouse_callback(float xPos, float yPos) { 
  if (mouseFirst) {
    lastX = xPos;
    lastY = yPos;
    mouseFirst = false;
  }

  
  float xoffset = xPos - lastX;
  float yoffset = lastY - yPos; 

  lastX = xPos;
  lastY = yPos;

  const float sensitivity = 0.3f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  if (pitch > 70.0f) pitch = 70.0f;
  if (pitch < -70.0f) pitch = -70.0f;

}
