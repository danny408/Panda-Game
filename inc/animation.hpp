#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

class Animation {
 public:
  Animation();
  ~Animation();
  virtual void load_content(std::string text, sf::Image image,
                            sf::Vector2f position);
  virtual void unload_content();
  virtual void update(sf::Time delta_time);
  virtual void set_alpha(float alpha);
  virtual void draw(sf::RenderWindow &window);
  float get_alpha();
  void set_active(bool value);

 protected:
  float alpha;
  std::string pre_text;
  sf::Text text;
  sf::Image image;
  sf::Sprite sprite;
  sf::Texture texture;
  sf::Vector2f position;
  sf::Color text_color;
  bool active;
};

#endif  // Animation_H
