#include "Collider.h"
#include <math.h>
Collider::Collider(sf::RectangleShape& body):
    body(body)
{

}

Collider::~Collider()
{
    //dtor
}

bool Collider::CheckCollision(Collider other, sf::Vector2f& direction, float push)
{
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltax = otherPosition.x - thisPosition.x;
    float deltay = otherPosition.y - thisPosition.y;

    float intersectx = abs(deltax) - (otherHalfSize.x + thisHalfSize.x);
    float intersecty = abs(deltay) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectx < 0.0f && intersecty < 0.0f)
    {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if(intersectx > intersecty)
        {
            if (deltax > 0.0f)
            {
                Move(intersectx * (1.0f - push), 0.0f);
                other.Move(-intersectx * push, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            }
            else
            {
                Move(-intersectx * (1.0f - push), 0.0f);
                other.Move(intersectx * push, 0.0f);

                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        }
        else
        {
            if (deltay > 0.0f)
            {
                Move(0.0f, intersecty * (1.0f - push));
                other.Move(0.0f, -intersecty * push);

                direction.x = 0.0f;
                direction.y = 1.0f;
            }
            else
            {
                Move(0.0f, -intersecty * (1.0f - push));
                other.Move(0.0f, intersecty * push);

                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }


        return true;
    }
    return false;
}
