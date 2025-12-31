#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

class Player{
    public:
        Player();
        ~Player();
        void Draw();
        void Shoot();
        void Move();
        void Rotate();
    private:
    Texture2D image;
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float roatation;
};


#endif 