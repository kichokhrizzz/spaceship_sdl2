#include "player.h"
#include <cmath>
#include <iostream> // Para imprimir errores

// Constructor actualizado para incluir renderer y texturePath
Player::Player(int x, int y, int size, SDL_Color color, SDL_Renderer* renderer, const std::string& texturePath)
    : posX(x), posY(y), velX(0), velY(0), size(size), color(color), score(0), renderer(renderer), texture(nullptr)
{
    texture = loadTexture(texturePath);
}

// Destructor añadido para liberar la textura
Player::~Player()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
}

// Nueva función para cargar la textura desde un archivo PNG
SDL_Texture* Player::loadTexture(const std::string& path)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr)
    {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

void Player::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            velY -= PLAYER_SPEED;
            break;
        case SDLK_DOWN:
            velY += PLAYER_SPEED;
            break;
        case SDLK_LEFT:
            velX -= PLAYER_SPEED;
            break;
        case SDLK_RIGHT:
            velX += PLAYER_SPEED;
            break;

        // 2nd Step Shot
        case SDLK_SPACE:
            shoot();
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            velY += PLAYER_SPEED;
            break;
        case SDLK_DOWN:
            velY -= PLAYER_SPEED;
            break;
        case SDLK_LEFT:
            velX += PLAYER_SPEED;
            break;
        case SDLK_RIGHT:
            velX -= PLAYER_SPEED;
            break;
        }
    }
}

void Player::move()
{
    posX += velX;
    posY += velY;

    // Keep the player inside the screen bounds
    if (posX < 0)
    {
        posX = 0;
    }
    else if (posX + size > 1980)
    {
        posX = 1980 - size;
    }

    if (posY < 0)
    {
        posY = 0;
    }
    else if (posY + size > 720)
    {
        posY = 720 - size;
    }
}

// 2nd Step Shoot
void Player::shoot()
{
    SDL_Color white = {255, 255, 255, 255};
    // Instancias de Projectile (x, y , radius, velocidad, color)
    projectiles.push_back(Projectile(posX + size / 2, posY, 15, -15, white));
}

// 3rd Step Enemy
void Player::addEnemy()
{
    SDL_Color green = {35, 101, 51, 255};
    enemies.push_back(Enemy(rand() % 1980, 0, 20, green));
}

void Player::handleEnemies(SDL_Renderer *renderer)
{
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        it->move(posX, posY);

        bool hit = false;
        for (auto projIt = projectiles.begin(); projIt != projectiles.end();)
        {
            if (it->checkCollision(projIt->getX(), projIt->getY(), projIt->getRadius()))
            {
                score++;
                projIt = projectiles.erase(projIt);
                hit = true;
            }
            else
            {
                ++projIt;
            }
        }

        if (hit)
        {
            it = enemies.erase(it);
        }
        else
        {
            it->render(renderer);
            ++it;
        }
    }
}

void Player::render(SDL_Renderer *renderer, TTF_Font *font, SDL_Color textColor)
{
    SDL_Rect renderQuad = {posX, posY, size, size};
    if (texture != nullptr)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &renderQuad);
    }

    // 2nd Step Shoot
    handleProjectiles(renderer);

    // 3rd Step Enemy
    handleEnemies(renderer);

    // 4th Step Score
    // Renderizar puntaje
    std::string scoreText = "Score: " + std::to_string(score);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuadText = {1980 - textWidth - 10, 10, textWidth, textHeight};
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuadText);
    SDL_DestroyTexture(textTexture);
}

// 2nd Step Shoot
void Player::handleProjectiles(SDL_Renderer *renderer)
{
    for (auto it = projectiles.begin(); it != projectiles.end();)
    {
        it->move();
        if (it->isOffScreen(720))
        {
            it = projectiles.erase(it);
        }
        else
        {
            it->render(renderer);
            ++it;
        }
    }
}
