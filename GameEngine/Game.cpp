#include "Game.h"

Game::Game() {
  this->initVariables();
  this->initSettings();
  this->initWindow();
}

Game::~Game() { delete this->window; }

void Game::update() { this->pollEvents(); }

void Game::draw() { this->window->display(); }

const bool Game::is_running() const { return window->isOpen(); }

void Game::initWindow() {
  videoMode.height = 600;
  videoMode.width = 800;

  window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initVariables() { this->window = nullptr; }

void Game::initSettings() {}

void Game::pollEvents() {
  while (this->window->pollEvent(this->ev)) {
    switch (ev.type) {
      case sf::Event::Closed:
        break;
      case sf::Event::KeyPressed:
        break;
      default:
        break;
    }
  }
}
