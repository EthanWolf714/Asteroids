#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "raylib.h"
#include <cstdlib>

typedef enum AsteroidSize
{
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 4
} AsteroidSize;

#define ASTEROID_ROT_SPEED_MIN 5
#define ASTEROID_ROT_SPEED_MAX 240


typedef struct Asteroid
{
    bool active;
    Vector2 position;
    Vector2 velocity;
    float rotation;
    float rotationSpeed;
    
} Asteroid;


Asteroid CreatAsteroid(Vector2 position, Vector2 velocity)
{
    Asteroid asteroid = {
        .active = true,
        .position = position,
        .velocity = velocity,
        .rotation = rand() % 360,
        .rotationSpeed = GetRandomValue(ASTEROID_ROT_SPEED_MIN, ASTEROID_ROT_SPEED_MAX)
    };
}
#endif