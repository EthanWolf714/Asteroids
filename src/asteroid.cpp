#include "asteroid.h"


Asteroid::Asteroid(){
    image = LoadTexture("build/SPRITES/ROCK.png");
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height)/2;
    scale = 2.0f;
}

Asteroid::~Asteroid(){
    UnloadTexture(image);
}

void Asteroid::Draw(){  
    DrawTextureEx(image, {position.x, position.y}, 0.0f,scale, WHITE);
}