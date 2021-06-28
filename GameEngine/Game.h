#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
 public:
  Game();
  virtual ~Game();
  void update();
  void draw();
  const bool is_running() const;

 private:
  sf::RenderWindow *window;
  sf::VideoMode videoMode;
  sf::ContextSettings settings;
  sf::Event ev;
  void initWindow();
  void initVariables();
  void initSettings();
  void pollEvents();
};
