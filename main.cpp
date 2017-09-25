#include <SFML/Graphics.hpp>
#include "Player.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1366 ,768), "SFML test",sf::Style::Fullscreen);


    sf::Texture playerTexture;
    playerTexture.loadFromFile("pokarla.png");





    Player player(&playerTexture, sf::Vector2u(3,4), 0.2f, 100.0f, 100.0f);

    float dTime=0.0f;
    sf::Clock clock;


    while (window.isOpen())
    {

        dTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }


        player.update(dTime);


        window.clear(sf::Color::White);
        player.draw(window);
        window.display();

    }

    return 0;
}
