#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speedx, float speedy) :
    animation(texture, imageCount, switchTime)
{
    this->speedx=speedx;
    this->speedy=speedy;
    row = 0;
    faceRight = true;


    body.setSize(sf::Vector2f(75.0f,100.0f));
    body.setTexture(texture);


}

Player::~Player()
{
    //dtor
}
void Player::draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speedx * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speedx * deltaTime;
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::S)))
        movement.y += speedy * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speedy * deltaTime;
    if(movement.x == 0.0f)
        row = 0;
    else
    {
        row = 1;
        if(movement.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    if(movement.y > 0)
        row = 2;
    else if(movement.y < 0)
        row = 3;
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}
