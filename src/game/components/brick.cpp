/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** brick.cpp
*/

#include "../../../include/brick.hpp"

Brick::Brick(Vector2 positionRelative, Vector3 position) : _name("brick")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/brick.png");
    _broke = false;
}

std::string Brick::getName()
{
    return (_name);
}

Vector3 Brick::getPosition() const
{
    return (_position);
}

Vector2 Brick::getPositionRelative() const
{
    return (_positionRelative);
}

void Brick::setPosition(char position, float number)
{
    switch (position)
    {
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

void Brick::setPosition(Vector3 position)
{
    _position = position;
}

void Brick::draw()
{
    if (_broke == false)
        DrawCubeTexture(_texture, _position, 1.0f, 1.0f, 1.0f, WHITE);
}

void Brick::destroy()
{
    UnloadTexture(_texture);
    _broke = true;
    _positionRelative.x = 84.0f;
    _positionRelative.y = 84.0f;
}