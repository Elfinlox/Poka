#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"


class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speedx, float speedy);
        virtual ~Player();

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        float speedx;
        float speedy;
        bool faceRight;

};

#endif // PLAYER_H
