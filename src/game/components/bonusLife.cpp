/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bonusLife
*/

#include "../../../include/bonusLife.hpp"

BonusLife::BonusLife(Vector2 positionRelative, Vector3 position) : _name("bonusLife")
{
    _positionRelative = positionRelative;
    _position = position;
    _texture = LoadTexture("../resources/bonusLife.png");
}

std::string BonusLife::getName()
{
    return (_name);
}

Vector3 BonusLife::getPosition() const
{
    return (_position);
}

Vector2 BonusLife::getPositionRelative() const
{
    return (_positionRelative);
}

void BonusLife::setPosition(char position, float number)
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

void BonusLife::setPositionRealtive(Vector2 position)
{
     _positionRelative = position;
}

void BonusLife::setPosition(Vector3 position)
{
    _position = position;
}

void BonusLife::draw()
{
    DrawCubeTexture(_texture, _position, 0.5f, 0.5f, 0.5f, WHITE);
}

void BonusLife::destroy()
{
    UnloadTexture(_texture);
    _positionRelative.x = 84.0f;
    _positionRelative.y = 84.0f;
    setPosition((Vector3){84.0f, 84.0f, 84.0f});
}