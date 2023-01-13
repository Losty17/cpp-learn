#include <set>
#include <algorithm>

#include "raylib.h"
#include "lib/GameObject.h"
#include "lib/Player.h"
#include "lib/Bullet.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

using namespace std;

const static void MainLoop(set<GameObject*>& gameObjects);

int main(void)
{
    SetTraceLogLevel(LOG_ALL);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");
    SetTargetFPS(60);

    set<GameObject*> gameObjects{
        // new player(gameObjects, Vector2{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}),
    };

    while (!WindowShouldClose()) MainLoop(gameObjects);

    CloseWindow();
    return 0;
}

const static void MainLoop(set<GameObject *> &gameObjects)
{
    if (IsKeyPressed(KEY_A)) gameObjects.insert(new Bullet());
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(20, 20);

    set<GameObject *> toDelete;

    for (auto object : gameObjects)
    {
        if (object->toDelete)
        {
            toDelete.insert(object);
            continue;
        }

        object->keybinds();
        object->update();

        object->draw();
    }

    EndDrawing();

    for (auto object : toDelete)
    {
        gameObjects.erase(object);
        delete object;        
    }
}