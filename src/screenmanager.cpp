#include "inc/screenmanager.hpp"

GameScreen *current_screen, *new_screen;

ScreenManager &ScreenManager::get_instance() {
  static ScreenManager instance;
  return instance;
}

ScreenManager::ScreenManager() {}

ScreenManager::~ScreenManager() {}

void ScreenManager::initialize() { current_screen = new SplashScreen(); }

void ScreenManager::load_content() { current_screen->load_content(); }

void ScreenManager::unload_content() {}

void ScreenManager::update(sf::RenderWindow &window, sf::Event event) {
  current_screen->update(window, event);
}

void ScreenManager::draw(sf::RenderWindow &window) {
  current_screen->draw(window);
}

void ScreenManager::add_screen(GameScreen *screen) {
  current_screen->unload_content();
  delete current_screen;
  current_screen = screen;
  current_screen->load_content();
}
