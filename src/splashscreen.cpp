#include "inc/splashscreen.hpp"

SplashScreen::SplashScreen() {}

SplashScreen::~SplashScreen() {}

void SplashScreen::load_content() {
  if (!font.loadFromFile("H:/QtBuilds/PandaGame/rsc/FiraCode-Regular.ttf")) {
    std::cout << "Cant find font\n";
  }
  text.setString("SplashScreen");
  text.setFont(font);

  keys.push_back(sf::Keyboard::Z);
  keys.push_back(sf::Keyboard::Return);
}

void SplashScreen::unload_content() { GameScreen::unload_content(); }

void SplashScreen::update(sf::RenderWindow &window, sf::Event event) {
  input.update(event);
  if (input.key_pressed(keys)) {
    ScreenManager::get_instance().add_screen(new TitleScreen);
  }
}

void SplashScreen::draw(sf::RenderWindow &window) { window.draw(text); }
