#include "raylib.h"
#include "game.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Asteroids!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Game game;
    bool pause;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_ENTER)){
            pause = !pause;
        }
        if(!game.IsGameOver() && !pause){
            game.Update();
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        if (!game.IsGameOver()) {
            game.Draw();
            

            if(pause){
            DrawText("Paused",350, 130, 40, GREEN);
        }

        } else {
            // Draw game over screen
            DrawText("GAME OVER", 280, 130, 40, RED);
            DrawText("Press ESC to exit", 180, 200, 50, WHITE);
        }

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    CloseWindow();
           // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
