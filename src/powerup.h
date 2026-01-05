#include "raylib.h"
#include <string>
#ifndef POWERUP_H
#define POWERUP_H

class PowerUp{
    public:
        PowerUp( Vector2 startPos,Texture2D* texture);
        ~PowerUp();
        void Update();
        void Draw();
        Rectangle GetRect();
        


    private:
        Vector2 position;
        Texture2D* extraLife;
        Texture2D* sheild;
        bool status;
        float scale;
        Texture2D* image;
        

};




#endif