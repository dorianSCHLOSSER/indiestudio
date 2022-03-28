/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** border.cpp
*/

#include "../../../include/border.hpp"

Border::Border(Vector2 positionRelative, Vector3 position) : _name("border")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/border.png");
}

std::string Border::getName()
{
    return (_name);
}

Vector3 Border::getPosition() const
{
    return (_position);
}

Vector2 Border::getPositionRelative() const
{
    return (_positionRelative);
}

void Border::setPosition(char position, float number)
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

void Border::setPosition(Vector3 position)
{
    _position = position;
}

void Border::draw()
{
    DrawCubeTexture(_texture, _position, 1.0f, 1.0f, 1.0f, WHITE);
}

void Border::destroy()
{
    UnloadTexture(_texture);
}