/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** core.cpp
*/

#include "../include/core.hpp"

Core::Core()
{
    _game = std::make_unique<Game>();
}

void Core::initialization()
{
    _screenWidth = 1800;
    _screenHeight = 900;

    InitWindow(_screenWidth, _screenHeight, "Indie Studio - Bomberman");
    InitAudioDevice();

    _camera = { { 0.0f, 25.0f, 7.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 35.0f, 0 };

    SetTargetFPS(60);
}

void Core::core_loop()
{
    int sys = system("python3 ../maps/generate_map.py > ../maps/main_map.txt");
    _game->parseMap();
    _game->initBackground();
    _game->initSounds();
    _background  = LoadTexture("../resources/menu.png");
    bool play = false;
    while (!WindowShouldClose()) {
        if (IsKeyReleased(KEY_ENTER)) play = true;
        if (play == true) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(_camera);
            _game->commandsPlayer();
            _game->checkIBombs();
            _game->checkIBonus();
            _game->drawGame();
            EndMode3D();
            _game->draw2DHUD();
            _game->checkFinal();
            DrawFPS(10, 10);
            EndDrawing();
        } else {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(_background, 0, 0, WHITE);
            EndDrawing();
        }
    }
}

void Core::close_loop()
{
    CloseWindow();
}