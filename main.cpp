#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>  // Añadido para manejar imágenes PNG
#include <SDL2/SDL_ttf.h>
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Inicializa SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Inicializa SDL_ttf
    if (TTF_Init() == -1)
    {
        SDL_Log("Unable to initialize SDL_ttf: %s", TTF_GetError());
        IMG_Quit();  // Debe cerrar SDL_image antes de SDL_Quit
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1980,
        720,
        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        TTF_Quit();  // Debe cerrar SDL_ttf antes de IMG_Quit
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Inicializa SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // 4th Step Score
    TTF_Font *font = TTF_OpenFont("/Users/jhoselbadillocortes/Documents/sdl_test/bit.ttf", 28); // Cambiar la ruta de la fuente según sea necesario
    if (font == NULL)
    {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Color textColor = {255, 255, 255, 255};

    srand(static_cast<unsigned>(time(0)));

    // 4th Step Score
    Player player(100, 100, 32, {255, 0, 0, 255}, renderer, "/Users/jhoselbadillocortes/Documents/sdl_test/spachesip.png");

    bool quit = false;
    SDL_Event e;
    int spawnTimer = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            player.handleEvent(e);
        }

        player.move();

        if (spawnTimer++ > 480) // Adjust spawn rate as needed
        {
            player.addEnemy();
            spawnTimer = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        player.render(renderer, font, textColor);

        SDL_RenderPresent(renderer);
    }

    // 4th Step
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Limpiar SDL_image
    IMG_Quit();
    // Limpiar SDL_ttf
    TTF_Quit();
    // Limpiar SDL
    SDL_Quit();

    return 0;
}
