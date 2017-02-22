#include "inc/gamescreen.hpp"

GameScreen::GameScreen() {}

GameScreen::~GameScreen() {}

void GameScreen::load_content() {}

void GameScreen::unload_content() {
  keys.clear();
  //  input = NULL;
}

void GameScreen::update(sf::RenderWindow &window, sf::Event event) {}

void GameScreen::draw(sf::RenderWindow &window) {}
