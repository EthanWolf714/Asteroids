#include "player.h"

Player::Player()
{
    image = LoadTexture("build/SPRITES/PLAYER.png");
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height) / 2;

}

Player::~Player(){
    UnloadTexture(image);

}

void Player::Draw(){
    DrawTextureV(image, position, WHITE);
}