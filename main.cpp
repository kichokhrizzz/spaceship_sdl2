#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "constanst.h"
#include <cstdlib>
#include <ctime>

void showGameOver(SDL_Renderer* renderer, TTF_Font* font)
{
    SDL_Color textColor = {255, 0, 0, 255};
    std::string gameOverText = "Game Over!";
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, gameOverText.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuad = {SCREEN_WIDTH / 2 - textWidth / 2, SCREEN_HEIGHT / 2 - textHeight / 2, textWidth, textHeight};
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);
    SDL_DestroyTexture(textTexture);
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() == -1)
    {
        SDL_Log("Unable to initialize SDL_ttf: %s", TTF_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        TTF_Quit();
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

    TTF_Font *font = TTF_OpenFont("/Users/jhoselbadillocortes/Documents/sdl_test/bit.ttf", 28);
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

    Player player(100, 100, 32, {255, 0, 0, 255}, renderer, "/Users/jhoselbadillocortes/Documents/sdl_test/spachesip.png");

    std::string enemyTexturePath = "/Users/jhoselbadillocortes/Documents/sdl_test/enemy.png";

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

        if (spawnTimer++ > 480)
        {
            player.addEnemy(renderer, enemyTexturePath);
            spawnTimer = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        player.render(renderer, font, textColor);

        if (player.isGameOver())
        {
            showGameOver(renderer, font);
            SDL_RenderPresent(renderer);
            SDL_Delay(3000); // Mostrar el mensaje de "Game Over" durante 3 segundos
            quit = true;
        }
        else
        {
            player.handleEnemies(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
