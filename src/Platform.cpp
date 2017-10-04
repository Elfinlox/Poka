#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
    body.setSize(size);
    body.setTexture(texture);
    body.setPosition(position);
    body.setOrigin(size/2.0f);

}

Platform::Platform()
{

}

Platform::~Platform()
{
}

void Platform::draw(sf::RenderWindow& window)
{
     window.draw(body);
}
