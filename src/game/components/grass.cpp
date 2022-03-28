/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** grass.cpp
*/

#include "../../../include/grass.hpp"

Grass::Grass(Vector2 positionRelative, Vector3 position) : _name("grass")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/grass.png");
}

std::string Grass::getName()
{
    return (_name);
}

Vector3 Grass::getPosition() const
{
    return (_position);
}

Vector2 Grass::getPositionRelative() const
{
    return (_positionRelative);
}

void Grass::setPosition(char position, float number)
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

void Grass::setPosition(Vector3 position)
{
    _position = position;
}

void Grass::draw()
{
    DrawCubeTexture(_texture, _position, 1.0f, 0.0f, 1.0f, YELLOW);
}

void Grass::destroy()
{
    UnloadTexture(_texture);
}

