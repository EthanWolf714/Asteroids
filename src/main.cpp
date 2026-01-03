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
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        game.Update();
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        if (!game.IsGameOver()) {
            game.Draw();
        } else {
            // Draw game over screen
            DrawText("GAME OVER", screenWidth + 300, screenHeight - 300, 40, RED);
            DrawText("Press ESC to exit", screenWidth + 300, screenHeight - 200, 20, WHITE);
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
