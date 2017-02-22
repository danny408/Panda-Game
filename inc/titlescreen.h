#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "inc/gamescreen.hpp"
#include "inc/screenmanager.hpp"
#include "inc/splashscreen.hpp"

class TitleScreen : public GameScreen {
 public:
  TitleScreen();
  ~TitleScreen();

  void load_content();
  void unload_content();
  void update(sf::RenderWindow &window, sf::Event event);
  void draw(sf::RenderWindow &window);

 private:
  sf::Text text;
  sf::Font font;
};

#endif  // TITLESCREEN_H
