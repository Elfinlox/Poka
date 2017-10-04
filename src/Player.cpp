#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f Position, float switchTime, float speedx, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->speedx = speedx;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;
    canMove = true;


    body.setSize(sf::Vector2f(75.0f,100.0f));
    body.setPosition(Position);
    body.setTexture(texture);
    body.setOrigin(body.getSize()/2.0f);


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
    velocity.x *= 0.5f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMove == true)
        velocity.x -= speedx;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMove == true)
        velocity.x += speedx;
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::W)) && canJump && canMove == true)
    {
        canJump = false;

        velocity.y = -sqrtf(2.0f * 9.81f * 100 * jumpHeight);
    }

    velocity.y += 9.81f * 100 * deltaTime;

    if(velocity.x == 0.0f)
        row = 0;
    else
    {
        row = 1;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    if(velocity.y > 0 && canJump == false)
        row = 2;
    else if(velocity.y < 0)
        row = 3;
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if(direction.x < 0.0f)
    {
        velocity.x = 0.0f;
    }
    else if(direction.x > 0.0f)
    {
        velocity.x = 0.0f;
    }
    if(direction.y < 0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
    }
    else if(direction.y > 0.0f)
    {
        velocity.y = 0.0f;
    }

}
