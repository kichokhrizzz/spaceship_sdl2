#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <string> // Añadido para manejar la ruta de la textura

class Enemy
{
public:
    Enemy(int x, int y, int size, SDL_Color color, SDL_Renderer *renderer, const std::string &texturePath); // Actualizado para incluir el renderer y la ruta de la textura
    void move(int targetX, int targetY);
    void render(SDL_Renderer *renderer);
    bool checkCollision(int projX, int projY, int projRadius);

    // Añadir métodos getX y getY
    int getX() const { return posX; }
    int getY() const { return posY; }
    int getSize() const { return size; } // Añadir este método

private:
    int posX, posY;
    int size;
    SDL_Color color;

    SDL_Texture *texture;   // Nueva variable para la textura del enemigo
    SDL_Renderer *renderer; // Nueva variable para el renderer

    SDL_Texture *loadTexture(const std::string &path); // Nueva función para cargar la textura
};

#endif // ENEMY_H
