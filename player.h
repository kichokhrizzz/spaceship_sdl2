#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string> // Añadido para manejar la ruta de la textura
#include "projectile.h"
#include "enemy.h"

class Player
{
public:
    Player(int x, int y, int size, SDL_Color color, SDL_Renderer* renderer, const std::string& texturePath); // Actualizado para incluir el renderer y la ruta de la textura
    ~Player(); // Destructor añadido para liberar la textura
    void handleEvent(SDL_Event &e);
    void move();
    //void render(SDL_Renderer *renderer); // Comentado para reemplazar por la nueva función de renderizado
    // 4th Step Score
    void render(SDL_Renderer *renderer, TTF_Font *font, SDL_Color textColor); // Actualizado para manejar la textura y renderizar el puntaje
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
    // 2nd Step Shoot
    std::vector<Projectile> projectiles;
    void handleProjectiles(SDL_Renderer *renderer);
    // 3rd Step Enemy
    std::vector<Enemy> enemies;

    // 4th Step Score
    int score; // Variable de puntaje

    SDL_Texture* texture; // Nueva variable para la textura del jugador
    SDL_Renderer* renderer; // Nueva variable para el renderer

    SDL_Texture* loadTexture(const std::string& path); // Nueva función para cargar la textura
};

#endif // PLAYER_H
