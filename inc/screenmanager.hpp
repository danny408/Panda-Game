#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include <string>
#include "inc/fadeanimation.hpp"
#include "inc/filemanager.hpp"
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
  void update(sf::RenderWindow &window, sf::Event event, sf::Time delta_time);
  void draw(sf::RenderWindow &window);
  void add_screen(GameScreen *screen);
  float get_alpha();

 private:
  // GameScreen *current_screen, *new_screen;
  ScreenManager();
  ScreenManager(ScreenManager const &);
  void operator=(ScreenManager const &);
  void Transition(sf::Time delta_time);

  bool transition;
  FadeAnimation fade;
  GameScreen *new_screen;
  FileManager file;
  std::vector<std::vector<std::string>> attributes;
  std::vector<std::vector<std::string>> contents;
};

#endif  // SCREENMANAGER_H
