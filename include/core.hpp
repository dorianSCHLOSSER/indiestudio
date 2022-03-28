/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include <memory>
#include <string>
#include <raylib.h>
#include <map>
#include <fstream>
#include <vector>
#include "game.hpp"

class Core
{
    public:
        Core();
        ~Core() {};

        void initialization();
        void core_loop();
        void close_loop();
    protected:
    private:
        Camera _camera;
        int _screenWidth;
        int _screenHeight;
        std::unique_ptr<Game> _game;
        Texture2D _background;
};

#endif /* !CORE_HPP_ */