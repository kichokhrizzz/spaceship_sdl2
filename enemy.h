#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

class Enemy
{
public:
    Enemy(int x, int y, int size, SDL_Color color);
    void move(int targetX, int targetY);
    void render(SDL_Renderer *renderer);
    bool checkCollision(int projX, int projY, int projRadius);

private:
    int posX, posY;
    int size;
    SDL_Color color;
};

#endif // ENEMY_H
