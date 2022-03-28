/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** wall.cpp
*/

#include "../../../include/wall.hpp"

Wall::Wall(Vector2 positionRelative, Vector3 position) : _name("wall")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/wall.png");
}

std::string Wall::getName()
{
    return (_name);
}

Vector3 Wall::getPosition() const
{
    return (_position);
}

Vector2 Wall::getPositionRelative() const
{
    return (_positionRelative);
}

void Wall::setPosition(char position, float number)
{
    switch (position) {
    case 'x':
        _position.x += number;
        break;
    case 'y':
        _position.y += number;
        break;
    case 'z':
        _position.z += number;
        break;
    default:
        break;
    }
}

void Wall::setPosition(Vector3 position)
{
    _position = position;
}

void Wall::draw()
{
    DrawCubeTexture(_texture, _position, 1.0f, 1.0f, 1.0f, WHITE);
}

void Wall::destroy()
{
    UnloadTexture(_texture);
}