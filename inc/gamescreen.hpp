#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "inc/filemanager.hpp"
#include "inc/inputmanager.hpp"

class GameScreen {
 public:
  GameScreen();
  ~GameScreen();

  virtual void load_content();
  virtual void unload_content();
  virtual void update(sf::RenderWindow &window, sf::Event event,
                      sf::Time delta_time);
  virtual void draw(sf::RenderWindow &window);

 protected:
  InputManager input;
  std::vector<sf::Keyboard::Key> keys;

  FileManager file;
  std::vector<std::vector<std::string>> attributes;
  std::vector<std::vector<std::string>> contents;
};

#endif  // GAMESCREEN_H
