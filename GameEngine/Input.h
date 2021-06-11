#pragma once
#include <SFML/Window.hpp>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

class Input {
 public:
   glm::vec3 GetMovementVector() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
       return vectorLeft;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      return vectorRight;
    } else {
      return glm::vec3(0.0f);
    }
   }

 private:
  const glm::vec3 vectorLeft = glm::vec3(-1.0f, 0.0f, 0.0f);
  const glm::vec3 vectorRight = glm::vec3(1.0f, 0.0f, 0.0f);
  const glm::vec3 vectorUp = glm::vec3(0.0f, 1.0f, 0.0f);
  const glm::vec3 vectorDown = glm::vec3(0.0f, -1.0f, 0.0f);
};