#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include "SFML/Graphics.hpp"

class InputManager {
 public:
  InputManager();
  ~InputManager();
  void update(sf::Event event);
  bool key_pressed(sf::Keyboard::Key key);
  bool key_pressed(std::vector<sf::Keyboard::Key> keys);

  bool key_released(sf::Keyboard::Key key);
  bool key_released(std::vector<sf::Keyboard::Key> keys);

  bool key_down(sf::Keyboard::Key key);
  bool key_down(std::vector<sf::Keyboard::Key> keys);

 private:
  sf::Event event;
};

#endif  // INPUTMANAGER_H
