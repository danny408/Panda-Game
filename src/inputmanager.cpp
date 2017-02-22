#include "inc/inputmanager.hpp"
#include <iostream>
InputManager::InputManager() {}

InputManager::~InputManager() {}

void InputManager::update(sf::Event event) { this->event = event; }

bool InputManager::key_pressed(sf::Keyboard::Key key) {
  if (event.key.code == key && event.type == sf::Event::KeyPressed) {
    return true;
  }
  return false;
}

bool InputManager::key_pressed(std::vector<sf::Keyboard::Key> keys) {
  for (unsigned int i = 0; i < keys.size(); i++) {
    if (key_pressed(keys[i])) {
      return true;
    }
  }
  return false;
}

bool InputManager::key_released(sf::Keyboard::Key key) {
  if (event.key.code == key && event.type == sf::Event::KeyReleased) {
    return true;
  }
  return false;
}

bool InputManager::key_released(std::vector<sf::Keyboard::Key> keys) {
  for (unsigned int i = 0; i < keys.size(); i++) {
    if (key_released(keys[i])) {
      return true;
    }
  }
  return false;
}

bool InputManager::key_down(sf::Keyboard::Key key) {
  if (sf::Keyboard::isKeyPressed(key)) {
    return true;
  }
  return false;
}

bool InputManager::key_down(std::vector<sf::Keyboard::Key> keys) {
  for (unsigned int i = 0; i < keys.size(); i++) {
    if (key_down(keys[i])) {
      return true;
    }
  }
  return false;
}
