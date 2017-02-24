#include "inc/fadeanimation.hpp"

FadeAnimation::FadeAnimation() {}

FadeAnimation::~FadeAnimation() {}

void FadeAnimation::load_content(std::string text, sf::Image image,
                                 sf::Vector2f position) {
  Animation::load_content(text, image, position);
  increase = false;
  fade_speed = 0.5f;
}

void FadeAnimation::unload_content() {}

void FadeAnimation::update(sf::Time delta_time) {
  if (active) {
    if (!increase) {
      alpha -= delta_time.asSeconds() * fade_speed;
    } else {
      alpha += delta_time.asSeconds() * fade_speed;
    }
    if (alpha >= 1.0f) {
      alpha = 1.0f;
      increase = false;
    } else if (alpha <= 0.0f) {
      alpha = 0.0f;
      increase = true;
    }
  } else {
    alpha = 1.0f;
  }
  Animation::update(delta_time);
}

void FadeAnimation::draw(sf::RenderWindow &window) { Animation::draw(window); }

void FadeAnimation::set_alpha(float value) {
  alpha = value;
  if (alpha == 0.0f) {
    increase = true;
  } else {
    increase = false;
  }
}
