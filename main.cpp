#include <SFML/Graphics.hpp>
#include "Animation.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1366 ,768), "SFML test",sf::Style::Fullscreen);
    sf::CircleShape player(50.0f);
    player.setOrigin(50.0f,50.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("pokarla.png");
    player.setTexture(&playerTexture);
    sf::Vector2u textureSize = playerTexture.getSize();



    Animation animation(&playerTexture, sf::Vector2u(3,1), 0.3f);

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.0f,-0.1f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.1f,0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.0f,0.1f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.1f,0.0f);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x,(float)mousePos.y);
        }
        animation.update(0, dTime);
        player.setTextureRect(animation.uvRect);

        window.clear(sf::Color::White);
        window.draw(player);
        window.display();

    }

    return 0;
}
