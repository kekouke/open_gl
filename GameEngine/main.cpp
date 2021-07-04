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

#include "Model.h"
#include "ElementBufferObject.h"

bool mouseFirst = true;
GLfloat yaw = 0.0f;
GLfloat pitch = 0.0f;
GLfloat lastX = 800 / 2.0;
GLfloat lastY = 600 / 2.0;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

void mouse_callback(float, float);
unsigned int loadCubemap(std::vector<std::string>);

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
  Shader skyboxShader("res/shaders/skybox.vs", "res/shaders/skybox.fs");
  Texture texture("res/imgs/wooden_container.png");
  Texture texture2("res/imgs/container_2_specular.png");

  Camera camera(vec3(0, 0, 3), glm::radians(70.0f));

  Shader backpackShader("res/shaders/backpack.vs", "res/shaders/backpack.fs");
  stbi_set_flip_vertically_on_load(true);
  Model backpack("C:/Users/Mi/Desktop/Models/backpack.obj");

  float vertices[] = {
         // координаты        // нормали           // текстурные координаты
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f
  };

float skyboxVertices[] = {        
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};

unsigned int cubeIndices[] = {0,  1,  2,  0,  2,  3,

                       4,  5,  6,  4,  6,  7,

                       8,  9,  10, 8,  10, 11,

                       12, 13, 14, 12, 14, 15,

                       16, 17, 18, 16, 18, 19,

                       20, 21, 22, 20, 22, 23};


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

  glm::vec3 modelPositions[] = {
    glm::vec3(0.0f, 0.0f, 10.0f),
    glm::vec3(0.0f, 0.0f, -10.0f),
    glm::vec3(10.0f, 0.0f, 0.0f),
    glm::vec3(-10.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 10.0f, 0.0f),
    glm::vec3(0.0f, -10.0f, 0.0f)
  };

  
  glm::vec3 pointLightPositions[] = {
      glm::vec3(0.7f, 0.2f, 2.0f),
      glm::vec3(2.3f, -3.3f, -4.0f),
      glm::vec3(-4.0f, 2.0f, -12.0f),
      glm::vec3(0.0f, 0.0f, -3.0f)
  }; 


  vector<std::string> faces = {
    "res/imgs/skybox/right.jpg",
    "res/imgs/skybox/left.jpg",
    "res/imgs/skybox/top.jpg",
    "res/imgs/skybox/bottom.jpg",
    "res/imgs/skybox/front.jpg",
    "res/imgs/skybox/back.jpg"
  };
  unsigned int cubemapTexture = loadCubemap(faces);

  
  VertexBufferObject skyboxVBO(skyboxVertices, sizeof(skyboxVertices) / sizeof(float));
  VertexAttributeObject skyboxVAO;
  skyboxVBO.Bind();
  skyboxVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  VertexAttributeObject cubeVAO;
  VertexBufferObject VBO(vertices, sizeof(vertices) / sizeof(float));

  cubeVAO.Bind();

  ElementBufferObject cubeEBO(cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));

  cubeVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  cubeVAO.EnableVertexAttribArray(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  cubeVAO.EnableVertexAttribArray(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

  VertexAttributeObject lightVAO;
  lightVAO.Bind();
  cubeEBO.Bind();
  lightVAO.EnableVertexAttribArray(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

  VBO.Bind();

  float cameraSpeed = 0.1f;

  cubeShader.Use();
  cubeShader.SetInt("material.diffuse", 0);
  cubeShader.SetInt("material.specular", 1);

  skyboxShader.Use();
  skyboxShader.SetInt("skybox", 0);

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
            camera.translate(-vec3::cross_product(camera.getFront(), camera.getUp()).normalize() * cameraSpeed);
          }
          if (windowEvent.key.code == sf::Keyboard::D) {
            camera.translate(vec3::cross_product(camera.getFront(), camera.getUp()).normalize() * cameraSpeed);
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

    for (unsigned int i = 0; i < 9; i++) {
      glm::mat4 model{1.0f};
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      cubeShader.SetMat4("model", model);

      glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
    }


    lampShader.Use();
    lampShader.SetMat4("projection", prj);
    lampShader.SetMat4("view", view);

    for (int i = 0; i < 4; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, pointLightPositions[i]);
      model = glm::scale(model, glm::vec3(0.2f));
      lampShader.SetMat4("model", model);

      glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
    }

    backpackShader.Use();
    lampShader.SetMat4("projection", prj);
    lampShader.SetMat4("view", view);

    for (int i = 0; i < 6; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, modelPositions[i]);
      model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
      backpackShader.SetMat4("model", model);

      backpack.Render(backpackShader);
    }



    glDepthFunc(GL_LEQUAL);
    skyboxShader.Use();
    view = camera.get_view_mat3();
    skyboxShader.SetMat4("view", view);
    skyboxShader.SetMat4("projection", prj);

    skyboxVAO.Bind();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);

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

unsigned int loadCubemap(std::vector<std::string> faces) {
  stbi_set_flip_vertically_on_load(false);
  unsigned int textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

  int width, height, nrChannels;
  for (unsigned int i = 0; i < faces.size(); i++) {
    unsigned char* data =
        stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
    if (data) {
      glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height,
                   0, GL_RGB, GL_UNSIGNED_BYTE, data);
      stbi_image_free(data);
    } else {
      std::cout << "Cubemap texture failed to load at path: " << faces[i]
                << std::endl;
      stbi_image_free(data);
    }
  }
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return textureID;
}