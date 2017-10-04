#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f Position, float switchTime, float speedx, float jumpHeight);
        virtual ~Player();

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);
        void OnCollision(sf::Vector2f direction);
        void cannotMove(){canMove = false;}
        Collider GetCollider(){return Collider(body);}
        sf::Vector2f GetPosition(){return body.getPosition();}


    private:
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        float speedx;
        float speedy;
        bool faceRight;
        sf::Vector2f velocity;
        bool canJump;
        bool canMove;
        float jumpHeight;

};

#endif // PLAYER_H
