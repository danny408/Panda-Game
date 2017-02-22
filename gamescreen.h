#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "inputmanager.h"

class GameScreen {
 public:
  GameScreen();
  ~GameScreen();

  virtual void load_content();
  virtual void unload_content();
  virtual void update(sf::RenderWindow &window, sf::Event event);
  virtual void draw(sf::RenderWindow &window);

 protected:
  InputManager input;
  std::vector<sf::Keyboard::Key> keys;
};

#endif  // GAMESCREEN_H
