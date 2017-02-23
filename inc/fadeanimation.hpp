#ifndef FADEANIMATION_H
#define FADEANIMATION_H

#include "inc/animation.hpp"

class FadeAnimation : public Animation {
 public:
  FadeAnimation();
  ~FadeAnimation();
  void load_content(std::string text, sf::Image image, sf::Vector2f position);
  void unload_content();
  void update(sf::Time delta_time);
  void draw(sf::RenderWindow &window);
  void set_alpha(float value);

 private:
  bool increase;
  float fade_speed;
};

#endif  // FADEANIMATION_H
