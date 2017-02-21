#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Main.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Config.hpp"
#include "SFML/Window.hpp"

#include "animation.hpp"

#include <QIcon>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Panda Game!");

    //Animation Stuff
    sf::Texture panda_sprite_sheet;
    if(!panda_sprite_sheet.loadFromFile("H:/Qtbuilds/Pandagame/panda_sprite_sheet.png")){
        return -1;
    }

    sf::Image panda_ico;
    if(!panda_ico.loadFromFile("H:/Qtbuilds/Pandagame/panda_64.bmp")){
        return -1;
    }
    cout << "Gucci!\n";
    window.setIcon(64,64,panda_ico.getPixelsPtr());


    sf::Texture bamboo;
    bamboo.loadFromFile("H:/Qtbuilds/Pandagame/bamboo.png");

    sf::Sprite bamboo_bg(bamboo);
    bamboo_bg.scale(2.0f,2.0f);

    sf::Sprite panda_sprite(panda_sprite_sheet);
    panda_sprite.setPosition(550,675);
    panda_sprite.scale(2.5f,2.5f);

    Animation panda_animation;
    panda_animation.addFrame(sf::IntRect(0,13,45,37),5.0f);
    panda_animation.addFrame(sf::IntRect(518,175,57,51),5.0f);
    panda_animation.addFrame(sf::IntRect(145,125,45,40),5.0f);
    panda_animation.addFrame(sf::IntRect(196,120,34,45),5.0f);

    //Game Clock
    sf::Clock clock;

    //Game SoundTrack
    sf::Music soundtrack;
    if(!soundtrack.openFromFile("H:/QtBuilds/PandaGame/Feather.ogg")){
            return -1;
    }
    soundtrack.play();
    soundtrack.setLoop(true);

    bool direction = true; // left , false = right;
    //Event Loop
    sf::Event event;
    while (window.isOpen()) {

        int x = panda_sprite.getPosition().x;
        int y = panda_sprite.getPosition().y;
        float deltaTime = clock.getElapsedTime().asSeconds();

        while (window.pollEvent(event)) {
            switch (event.type) {
                   // window closed
                   case sf::Event::Closed:
                       window.close();
                       break;
                   // we don't process other types of events
                   default:
                       break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if(y >= 5){
               panda_sprite.move(0,-.5*deltaTime);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if(x >= 5){
               panda_sprite.move(-.5*deltaTime,0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if(y <= 835){
               panda_sprite.move(0,.5*deltaTime);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if(x <= 1080){
               panda_sprite.move(.5*deltaTime,0);
            }
        }

        //sample ping pong type left to right movement
        if(x <= 5){
            direction = false;
        }
        else if(x >= 1080){
            direction = true;
        }

        if(direction){
            if( clock.getElapsedTime().asSeconds() >= .25){
                panda_sprite.move(-5,0);
                clock.restart();
            }
        }
        else{
            if( clock.getElapsedTime().asSeconds() >= .25){
                panda_sprite.move(5,0);
                clock.restart();
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
