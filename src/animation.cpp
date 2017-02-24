#include "inc/animation.hpp"

Animation::Animation() {}

Animation::~Animation() {}

void Animation::load_content(std::string text, sf::Image image,
                             sf::Vector2f position) {
  this->pre_text = text;
  this->image = image;
  this->position = position;
  alpha = 1.0f;
  text_color = sf::Color(114, 77, 255);
  if (image.getSize().y > 0) {
    texture.loadFromImage(this->image);
    sprite.setTexture(texture);
  }
  this->text.setString(text);
  active = false;
}

void Animation::unload_content() {}
void Animation::update(sf::Time delta_time) {
  sprite.setColor(sf::Color(255, 255, 255, 255 * alpha));
}

void Animation::draw(sf::RenderWindow &window) {
  std::string str = text.getString();
  if (str != "") {
    window.draw(text);
  }
  if (sprite.getTexture() != NULL) {
    window.draw(sprite);
  }
}

float Animation::get_alpha() { return alpha; }

void Animation::set_active(bool value) { active = value; }

void Animation::set_alpha(float alpha) {}
