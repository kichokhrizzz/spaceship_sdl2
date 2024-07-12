#include "enemy.h"
#include <cmath>

Enemy::Enemy(int x, int y, int size, SDL_Color color)
    : posX(x), posY(y), size(size), color(color)
{
}

void Enemy::move(int targetX, int targetY)
{
    int deltaX = targetX - posX;
    int deltaY = targetY - posY;
    float length = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (length != 0)
    {
        posX += static_cast<int>((deltaX / length) * 1.2); // Adjust the speed as needed
        posY += static_cast<int>((deltaY / length) * 1.1); // Adjust the speed as needed
    }
}

void Enemy::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect fillRect = {posX, posY, size, size};
    SDL_RenderFillRect(renderer, &fillRect);
}

bool Enemy::checkCollision(int projX, int projY, int projRadius)
{
    int deltaX = projX - posX;
    int deltaY = projY - posY;
    int distance = static_cast<int>(std::sqrt(deltaX * deltaX + deltaY * deltaY));

    return distance < (size / 2 + projRadius);
}
