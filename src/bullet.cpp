#include "bullet.h"
#include "player.h"
//constrcutor 
Bullet::Bullet(Vector2 startPos, Vector2 startSpeed, Texture2D* bulletTexture) {
    position = startPos;
    speed = startSpeed;
    image = bulletTexture;
    lifetime = 2.0f;
    active = true;
}

Bullet::~Bullet(){

}

void Bullet::Draw(){
    if(active){
        DrawTextureV(*image, position, WHITE);
    }
}


void Bullet::Update(){
    //update bullets position every frame
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();

    lifetime -= GetFrameTime();

    //when lifetime equals 0 deactivate
    if(lifetime <= 0){
        active = false;
    }

    
}

bool Bullet::IsActive(){
    return active;
}

Vector2 Bullet::GetPosition(){
    return position;
}

Rectangle Bullet::GetRect(){
    return Rectangle{position.x, position.y, (float)image->width, (float)image->height};
}

void Bullet::SetActive(bool value){
    active = value;
}