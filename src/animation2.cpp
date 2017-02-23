#include "inc/animation2.h"

Animation2::animation2() {}

Animation2::~animation2() {}

virtual void Animation2::load_content(std::string text, sf::Image image,
                                      sf::Vector2f position) {
  this->pre_text = text;
  this->image = image;
  this->position = position;
  alpha = 1.0f;
  text_color = sf::Color(114, 77, 255);
  texture.loadFromImage(image);
  sprite.setTexture(texture);
  this->text.setString(text);
}

virtual void Animation2::unload_content() {}

virtual void Animation2::update() {}

void Animation2::draw(sf::RenderWindow &window) {}
