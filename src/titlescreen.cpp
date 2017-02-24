#include "inc/titlescreen.hpp"

TitleScreen::TitleScreen() {}

TitleScreen::~TitleScreen() {}

void TitleScreen::load_content() {
  if (!font.loadFromFile("H:/QtBuilds/PandaGame/rsc/FiraCode-Regular.ttf")) {
    std::cout << "Cant find font\n";
  }
  text.setString("TitleScreen");
  text.setFont(font);

  keys.push_back(sf::Keyboard::Z);
  keys.push_back(sf::Keyboard::Return);
}

void TitleScreen::unload_content() { GameScreen::unload_content(); }

void TitleScreen::update(sf::RenderWindow &window, sf::Event event) {
  input.update(event);
  if (input.key_pressed(keys)) {
    ScreenManager::get_instance().add_screen(new SplashScreen);
  }
}

void TitleScreen::draw(sf::RenderWindow &window) { window.draw(text); }
