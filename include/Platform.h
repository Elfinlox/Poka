#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Graphics.hpp>
#include "Collider.h"


class Platform
{
    public:
        Platform();
        Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
        virtual ~Platform();
        void draw(sf::RenderWindow& window);
        Collider GetCollider(){return Collider(body);}

    private:
        sf::RectangleShape body;
};

#endif // PLATFORM_H
