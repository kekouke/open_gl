#pragma once

#include <GL/glew.h>
#include <iostream>

#include <cmath>

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

  glewExperimental = GL_TRUE;
  glEnable(GL_DEPTH_TEST);

  if (GLEW_OK != glewInit()) {
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.fs");
  Shader cubeShader("res/shaders/e4.vs", "res/shaders/e4.fs");
  Texture texture("res/imgs/wooden_container.png");
  Texture texture2("res/imgs/container_2_specular.png");

  Camera camera(glm::vec3(0, 0, 3), glm::radians(70.0f));

float vertices[] = {
     // координаты        // нормали           // текстурные координаты
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
 
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
 
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
 
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
 
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
 
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};


  glm::vec3 cubePositions[] = 
  {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f, 2.0f, -2.5f),
    glm::vec3(1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)
  };

  
  glm::vec3 pointLightPositions[] = {
      glm::vec3(0.7f, 0.2f, 2.0f),
      glm::vec3(2.3f, -3.3f, -4.0f),
      glm::vec3(-4.0f, 2.0f, -12.0f),
      glm::vec3(0.0f, 0.0f, -3.0f)
  };  

  VertexAttributeObject cubeVAO;
  VertexBufferObject VBO(vertices, sizeof(vertices) / sizeof(float));

  cubeVAO.Bind();
  cubeVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  cubeVAO.EnableVertexAttribArray(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  cubeVAO.EnableVertexAttribArray(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

  VertexAttributeObject lightVAO;
  lightVAO.Bind();
  VBO.Bind();
  lightVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

  float cameraSpeed = 0.1f;


  cubeShader.Use();
  cubeShader.SetInt("material.diffuse", 0);
  cubeShader.SetInt("material.specular", 1);

  sf::Clock clock;
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


    glClearColor(0, 0, 0, 0); // 0.2f, 0.3f, 0.3f, 1.0f
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto ticks = clock.getElapsedTime().asSeconds();
    
    cubeShader.Use();
    cubeShader.SetVec3("viewPos", camera.getPosition());
    cubeShader.SetVec3("material.specular", 0.5f, 0.5f, 0.5f);
    cubeShader.SetFloat("material.shininess", 64.0f);

    // Направленный свет
    cubeShader.SetVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
    cubeShader.SetVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
    cubeShader.SetVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
    cubeShader.SetVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

    // Точечный истоник света
     for (int i = 0; i < 4; i++) {
      std::stringstream s("pointLights[");
      s << "pointLights[" << i << "]";

      cubeShader.SetVec3(s.str() + ".position", pointLightPositions[i]);
      cubeShader.SetVec3(s.str() + ".ambient", 0.05f, 0.05f, 0.05f);
      cubeShader.SetVec3(s.str() + ".diffuse", 0.8f, 0.8f, 0.8f);
      cubeShader.SetVec3(s.str() + ".specular", 1.0f, 1.0f, 1.0f);
      cubeShader.SetFloat(s.str() + ".constant", 1.0f);
      cubeShader.SetFloat(s.str() + ".linear", 0.09);
      cubeShader.SetFloat(s.str() + ".quadratic", 0.032);
    }

     // Фонарик
    cubeShader.SetVec3("spotLight.position", camera.getPosition());
    cubeShader.SetVec3("spotLight.direction", camera.getFront());
    cubeShader.SetVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    cubeShader.SetVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    cubeShader.SetVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
    cubeShader.SetFloat("spotLight.constant", 1.0f);
    cubeShader.SetFloat("spotLight.linear", 0.09);
    cubeShader.SetFloat("spotLight.quadratic", 0.032);
    cubeShader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    cubeShader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));


    auto view = camera.getView();
    auto prj = camera.getProjection();

    cubeShader.SetMat4("view", view);
    cubeShader.SetMat4("projection", prj);

    texture.Bind(0);
    texture.Bind(1);

    cubeVAO.Bind();

    for (unsigned int i = 0; i < 10; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      cubeShader.SetMat4("model", model);

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    lampShader.Use();
    lampShader.SetMat4("projection", prj);
    lampShader.SetMat4("view", view);

    for (int i = 0; i < 4; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, pointLightPositions[i]);
      model = glm::scale(model, glm::vec3(0.2f));
      lampShader.SetMat4("model", model);

      lightVAO.Bind();

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }

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
