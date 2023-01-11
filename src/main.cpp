#include <vector>
#include "raylib.h"
#include "game_objects/object.h"
#include "game_objects/player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

using namespace std;

const static void MainLoop(const vector<Object*>& gameObjects);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");
    SetTargetFPS(60);

    vector<Object*> gameObjects{
        new Player(Vector2{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}),
    };

    while (!WindowShouldClose()) MainLoop(gameObjects);

    CloseWindow();
    return 0;
}

const static void   MainLoop(const vector<Object*>& gameObjects)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (Object* object : gameObjects)
    {
        object->keybinds();
        object->update();

        object->draw();
    }

    EndDrawing();
}