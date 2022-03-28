/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bonusBomb
*/

#include "../../../include/bonusBomb.hpp"

BonusBomb::BonusBomb(Vector2 positionRelative, Vector3 position) : _name("bonusBomb")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/bonusBomb.png");
}

std::string BonusBomb::getName()
{
    return (_name);
}

Vector3 BonusBomb::getPosition() const
{
    return (_position);
}

Vector2 BonusBomb::getPositionRelative() const
{
    return (_positionRelative);
}

void BonusBomb::setPosition(char position, float number)
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

void BonusBomb::setPosition(Vector3 position)
{
    _position = position;
}

void BonusBomb::setPositionRealtive(Vector2 position)
{
    _positionRelative = position;
}

void BonusBomb::draw()
{
    DrawCubeTexture(_texture ,_position, 0.5f, 0.5f, 0.5f, WHITE);
}

void BonusBomb::destroy()
{
    UnloadTexture(_texture);
    _positionRelative.x = 84.0f;
    _positionRelative.y = 84.0f;
    setPosition((Vector3){84.0f, 84.0f, 84.0f});
}