#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "inc/fadeanimation.hpp"
#include "inc/gamescreen.hpp"
#include "inc/screenmanager.hpp"
#include "inc/titlescreen.hpp"

class SplashScreen : public GameScreen {
 public:
  SplashScreen();
  ~SplashScreen();

  void load_content();
  void unload_content();
  void update(sf::RenderWindow &window, sf::Event event, sf::Time delta_time);
  void draw(sf::RenderWindow &window);

 private:
  sf::Text text;
  sf::Font font;

  sf::Image image;
  std::vector<FadeAnimation *> fade;
  int image_number;
};

#endif  // SPLASHSCREEN_H
