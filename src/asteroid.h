#ifndef ASTEROID_H
#define ASTEROID_H
#include "raylib.h"
#include "math.h"

class Asteroid {
    public:
        Asteroid();
        ~Asteroid();
        void Draw();
        void Update();
        void Move();
    private:
    Texture2D image;
    Vector2 position;
    float scale;
};



#endif