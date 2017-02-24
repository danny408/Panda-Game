#include "inc/screenmanager.hpp"

GameScreen *current_screen, *new_screen;

ScreenManager &ScreenManager::get_instance() {
  static ScreenManager instance;
  return instance;
}

ScreenManager::ScreenManager() {}

ScreenManager::~ScreenManager() {}

void ScreenManager::initialize() {
  current_screen = new SplashScreen();
  transition = false;

  file.load_content("H:/QtBuilds/PandaGame/load/splash.txt", attributes,
                    contents);
  //  sf::Image image;
  //  sf::Vector2f pos;
  //  fade.load_content("", image, pos);
}

void ScreenManager::load_content() {
  current_screen->load_content();

  sf::Image image;
  sf::Vector2f pos;
  fade.load_content("", image, pos);
  fade.set_alpha(0.0f);
}

void ScreenManager::unload_content() {}

void ScreenManager::update(sf::RenderWindow &window, sf::Event event,
                           sf::Time delta_time) {
  if (!transition) {
    current_screen->update(window, event, delta_time);
  }
  Transition(delta_time);
}

void ScreenManager::draw(sf::RenderWindow &window) {
  current_screen->draw(window);
}

void ScreenManager::add_screen(GameScreen *screen) {
  transition = true;
  new_screen = screen;
  fade.set_active(true);
  fade.set_alpha(0.0f);
}

void ScreenManager::Transition(sf::Time delta_time) {
  if (transition) {
    fade.update(delta_time);
    if (fade.get_alpha() >= 1.0f) {
      current_screen->unload_content();
      delete current_screen;
      current_screen = new_screen;
      current_screen->load_content();
      new_screen = nullptr;
    } else if (fade.get_alpha() <= 0.0f) {
      transition = false;
      fade.set_active(false);
    }
  }
}

float ScreenManager::get_alpha() { return fade.get_alpha(); }
