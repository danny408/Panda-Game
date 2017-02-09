#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Main.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Config.hpp"

#include "animation.hpp"

#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");

    sf::Texture panda_sprite_sheet;
    if(!panda_sprite_sheet.loadFromFile("H:/Qtbuilds/Pandagame/panda_sprite_sheet.png")){
        return -1;
    }

    sf::Texture bamboo;
    bamboo.loadFromFile("H:/Qtbuilds/Pandagame/bamboo.png");

    sf::Sprite bamboo_bg(bamboo);
    bamboo_bg.scale(2.0f,2.0f);

    sf::Sprite panda_sprite(panda_sprite_sheet);

    panda_sprite.scale(2.5f,2.5f);


    Animation panda_animation;
    panda_animation.addFrame(sf::IntRect(0,13,45,37),5.0f);
    panda_animation.addFrame(sf::IntRect(518,175,57,51),5.0f);
    panda_animation.addFrame(sf::IntRect(145,125,45,40),5.0f);
    panda_animation.addFrame(sf::IntRect(196,120,34,45),5.0f);


    sf::Clock clock;

    sf::Music soundtrack;
    if(!soundtrack.openFromFile("H:/QtBuilds/PandaGame/Feather.ogg")){
            return -1;
    }
    soundtrack.play();
    soundtrack.setLoop(true);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                   // window closed
                   case sf::Event::Closed:
                       window.close();
                       break;

                   // key pressed
                   case sf::Event::KeyPressed:
                        switch (event.key.code){
                            case sf::Keyboard::W:
                                if(panda_sprite.getPosition().y >= 5){
                                    panda_sprite.move(0,-5);
                                }
                                break;
                            case sf::Keyboard::A:
                                if(panda_sprite.getPosition().x >= 5){
                                    panda_sprite.move(-5,0);
                                }
                                break;
                            case sf::Keyboard::S:
                                if(panda_sprite.getPosition().y <= 835){
                                    panda_sprite.move(0,5);
                                }
                                break;
                            case sf::Keyboard::D:
                                if(panda_sprite.getPosition().x <= 1140){
                                    panda_sprite.move(5,0);
                                }
                                break;
                        }
                       break;

                   // we don't process other types of events
                   default:
                       break;

            }
        }

        panda_sprite.setTextureRect(panda_animation.getFrame());
        window.clear();
        window.draw(bamboo_bg);
        window.draw(panda_sprite);
        window.display();
    }

    return 0;
}
