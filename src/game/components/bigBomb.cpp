/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bigBomb
*/

#include "../../../include/bigBomb.hpp"

BigBomb::BigBomb() : _name("bigBomb"), _planted(false), _range(19) {}


Vector3 BigBomb::getPosition() const
{
    return (_position);
}

Vector2 BigBomb::getPositionRelative() const
{
    return (_positionRelative);
}

std::string BigBomb::getName()
{
    return (_name);
}

double BigBomb::getPlantedSince()
{
    return (_plantedSince);
}

bool BigBomb::isBeenPlanted()
{
    return (_planted);
}

int BigBomb::getRange()
{
    return (_range);
}

void BigBomb::setPlanted(bool state)
{
    _planted = state;
}

void BigBomb::setPlantedSince(double plantedSince)
{
    _plantedSince = plantedSince;
}

void BigBomb::setPosition(char position, float number)
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

void BigBomb::setPositionRelative(Vector2 position)
{
    _positionRelative = position;
}

void BigBomb::setPosition(Vector3 position)
{
    _position = position;
}

void BigBomb::draw()
{
    if (_plantedSince + 3.0 - 1.5 < GetTime()) {
        DrawSphere(_position, 0.50f, RED);
    } else {
        DrawSphere(_position, 0.50f, BLACK);
    }
}

void BigBomb::destroy()
{
    //destroy
}