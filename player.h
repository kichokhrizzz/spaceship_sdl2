#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "projectile.h"
#include "enemy.h"

class Player
{
public:
    Player(int x, int y, int size, SDL_Color color);
    void handleEvent(SDL_Event &e);
    void move();
    //void render(SDL_Renderer *renderer);
    // 4th Step Score
    void render(SDL_Renderer *renderer, TTF_Font *font, SDL_Color textColor);
    // 2nd Step Shoot
    void shoot();

    // 3rd Steep Enemy
    int getX() const { return posX; }
    int getY() const { return posY; }
    void addEnemy();
    void handleEnemies(SDL_Renderer *renderer);

    // 4th Steep Score
    int getScore() const { return score; }

private:
    int posX, posY;
    int velX, velY;
    int size;
    SDL_Color color;
    static const int PLAYER_SPEED = 1;
    // 2nd Steep Shoot
    std::vector<Projectile> projectiles;
    void handleProjectiles(SDL_Renderer *renderer);
    // 3rd Steep Enemy
    std::vector<Enemy> enemies;

    // 4th Step Score
    int score; // Variable de puntaje
};

#endif // PLAYER_H