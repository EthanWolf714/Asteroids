#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    Vector2 GetRandomEdgePosition();
    Vector2 GetRandomVelocity();

private:
    Player player;
    std::vector<Bullet> bullets;
    Texture2D bulletTexture;
    std::vector<Asteroid> asteroids;
    Texture2D asteroidTexture;
};

#endif
