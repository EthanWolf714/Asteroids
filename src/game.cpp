#include "game.h"
#include <algorithm>

Game::Game()
{
    //game loads texture once so its not being assigned every time a bullet is created
    bulletTexture = LoadTexture("build/SPRITES/BULLET.png");
    asteroidTexture = LoadTexture("build/SPRITES/ROCK.png");

   

    for(int i = 0; i < 10; i++){
            asteroids.push_back(Asteroid(
            GetRandomEdgePosition(),
            GetRandomVelocity(),
            3,
            &asteroidTexture
        ));

    }
}

Game::~Game()
{
    UnloadTexture(bulletTexture);
}

void Game::Draw()
{
    player.Draw();
    
    for(auto &asteroid : asteroids){
        asteroid.Draw();
    }

    //draw bullets stored in bullets array
    for (auto &bullet : bullets)
    {
        bullet.Draw();
    }
}

void Game::HandleInput()
{
    player.Move();
    player.Rotate();

    if (player.Shoot())
    {
        // calculate bullet direction from player rotation
        float angle = player.GetPlayerRotation() * DEG2RAD - (PI/2);
        float bulletSpeed = 500.f;
        //offset for bullet spawnign in front of the ship
        float spawnOffset = 15.f;

        //calculate spwan position of bullet, adding player position 
        //then multiply by offset to center it
        Vector2 spawnPos = {
            player.GetPlayerPosition().x + cos(angle) * spawnOffset,
            player.GetPlayerPosition().y + sin(angle) * spawnOffset,

        };

        // calculate bullet speed.
        Vector2 bulletVelocity = {
            //multiple player rotation and bulllet speed then add player speed
            //so bullets keep there velocity
            cos(angle) * bulletSpeed + player.GetPlayerSpeed().x,
            sin(angle) * bulletSpeed + player.GetPlayerSpeed().y
        } ;

        // create and add bullets to the bullets array
        bullets.push_back(Bullet(
            spawnPos,
            bulletVelocity,
            &bulletTexture));
    }
}

void Game::Update()
{
    HandleInput();

    // update all bullets
    for (auto &bullet : bullets)
    {
        bullet.Update();
    }

    for(auto &asteroid : asteroids){
        asteroid.Update();
    }

    // remove dead bullets marked as inactive
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
                       [](Bullet &b)
                       { return !b.IsActive(); }),
        bullets.end());

    
}

//spawn on random position on screen edge
Vector2 Game::GetRandomEdgePosition(){
    int edge  = GetRandomValue(0, 3);

    if (edge == 0) { // top
        return {(float)GetRandomValue(0, GetScreenWidth()), 0.0f};
    } else if (edge == 1) { // right
        return {(float)GetScreenWidth(), (float)GetRandomValue(0, GetScreenHeight())};
    } else if (edge == 2) { // bottom
        return {(float)GetRandomValue(0, GetScreenWidth()), (float)GetScreenHeight()};
    } else { // left
        return {0.0f, (float)GetRandomValue(0, GetScreenHeight())};
    }

    return {0.0f, 0.0f};
}

//calculates a random veolcity 
Vector2 Game::GetRandomVelocity(){
   return {
        (float)GetRandomValue(-200, 200),
        (float)GetRandomValue(-200, 200)
    };
}