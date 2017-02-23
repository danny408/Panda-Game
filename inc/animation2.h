#ifndef ANIMATION2_H
#define ANIMATION2_H

#include <string>
#include "SFML/Graphics.hpp"

class Animation2 {
 public:
  Animation2();
  ~Animation2();
  virtual void load_content(std::string text, sf::Image image,
                            sf::Vector2f position);
  virtual void unload_content();
  virtual void update();
  void draw(sf::RenderWindow &window);

 protected:
  float alpha;
  std::string pre_text;
  sf::Text text;
  sf::Image image;
  sf::Sprite sprite;
  sf::Vector2f position;
  sf::Color text_color;
};

#endif  // ANIMATION2_H
