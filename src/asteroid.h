#ifndef ASTEROID_H
#define ASTEROID_H
#include "raylib.h"
#include "math.h"

class Asteroid {
    public:
        Asteroid(Vector2 startPos, Vector2 startSpeed, int asteroidSize, Texture2D* asteroidTexture);
        ~Asteroid();
        void Draw();
        void Update();
        void Move();
        Vector2 GetPosition();
        bool isActive();
        int GetSize();
    private:
    Texture2D* image;
    Vector2 position;
    float scale;
    bool active;
    int size;
    Vector2 speed;
};



#endif