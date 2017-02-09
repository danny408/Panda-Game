#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Main.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Config.hpp"

#include <iostream>
int main()
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");

    sf::Texture panda;
    if(!panda.loadFromFile("H:/Qtbuilds/Pandagame/panda.png")){
        std::cout << "Error1\n";
        return -1;
    }
    panda.setSmooth(true);

    sf::Sprite panda_sprite;
    panda_sprite.setTexture(panda);
    panda_sprite.move(sf::Vector2f(300,300));
    panda_sprite.scale(sf::Vector2f(.25f,.25f));

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Music soundtrack;
    if(!soundtrack.openFromFile("H:/QtBuilds/PandaGame/Feather.ogg")){
            std::cout << "Error2\n";
            return -1;
    }
    soundtrack.play();
    soundtrack.setLoop(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(panda_sprite);
        window.display();
    }

    return 0;
}
