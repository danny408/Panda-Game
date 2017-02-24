#include "inc/splashscreen.hpp"

SplashScreen::SplashScreen() {}

SplashScreen::~SplashScreen() {}

void SplashScreen::load_content() {
  image_number = 0;
  if (!font.loadFromFile("H:/QtBuilds/PandaGame/rsc/FiraCode-Regular.ttf")) {
    std::cout << "Cant find font\n";
  }
  text.setString("SplashScreen");
  text.setFont(font);

  keys.push_back(sf::Keyboard::Z);
  keys.push_back(sf::Keyboard::Return);

  file.load_content("H:/QtBuilds/PandaGame/load/splash.txt", attributes,
                    contents);

  for (int i = 0; i < attributes.size(); i++) {
    for (int j = 0; j < attributes[i].size(); j++) {
      std::string att = attributes[i][j];
      if (att == "Image") {
        sf::Vector2f pos(0, 0);
        image.loadFromFile(contents[i][j]);
        fade.push_back(new FadeAnimation);
        fade[fade.size() - 1]->load_content("", image, pos);
        fade[fade.size() - 1]->set_active(true);
      }
    }
  }
}

void SplashScreen::unload_content() {
  GameScreen::unload_content();
  for (int i = 0; i < fade.size(); i++) {
    fade[i]->unload_content();
    delete fade[i];
  }
  fade.clear();
}

void SplashScreen::update(sf::RenderWindow& window, sf::Event event,
                          sf::Time delta_time) {
  input.update(event);

  if (fade[image_number]->get_alpha() <= 0.0f) {
    image_number++;
  }

  if (image_number != fade.size() - 1) {
    fade[image_number]->update(delta_time);
  }

  if (input.key_pressed(keys) || image_number >= fade.size() - 1) {
    ScreenManager::get_instance().add_screen(new TitleScreen);
  }
}

void SplashScreen::draw(sf::RenderWindow& window) {
  // window.draw(text);
  fade[image_number]->draw(window);
}
