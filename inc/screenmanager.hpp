#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include <string>
#include "inc/gamescreen.hpp"
#include "inc/splashscreen.hpp"
#include "inc/titlescreen.hpp"

#define SCREENWIDTH 1200
#define SCREENHEIGHT 900

class ScreenManager {
 public:
  ~ScreenManager();
  static ScreenManager &get_instance();
  void initialize();
  void load_content();
  void unload_content();
  void update(sf::RenderWindow &window, sf::Event event);
  void draw(sf::RenderWindow &window);
  void add_screen(GameScreen *screen);

 private:
  // GameScreen *current_screen, *new_screen;
  ScreenManager();
  ScreenManager(ScreenManager const &);
  void operator=(ScreenManager const &);
};

#endif  // SCREENMANAGER_H
