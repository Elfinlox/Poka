#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        virtual ~Animation();
        void update(int row, float deltaTime, bool faceRight);

        sf::IntRect uvRect;


    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;

        float switchTime;
        float totalTime;
};

#endif // ANIMATION_H
