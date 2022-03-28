/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bomb
*/

#include "../../../include/bomb.hpp"

Bomb::Bomb() : _name("bomb"), _planted(false), _range(4) {}


Vector3 Bomb::getPosition() const
{
    return (_position);
}

Vector2 Bomb::getPositionRelative() const
{
    return (_positionRelative);
}

std::string Bomb::getName()
{
    return (_name);
}

double Bomb::getPlantedSince()
{
    return (_plantedSince);
}

bool Bomb::isBeenPlanted()
{
    return (_planted);
}

int Bomb::getRange()
{
    return (_range);
}

void Bomb::setPlanted(bool state)
{
    _planted = state;
}

void Bomb::setPlantedSince(double plantedSince)
{
    _plantedSince = plantedSince;
}

void Bomb::setPosition(char position, float number)
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

void Bomb::setPositionRelative(Vector2 position)
{
    _positionRelative = position;
}

void Bomb::setPosition(Vector3 position)
{
    _position = position;
}

void Bomb::draw()
{
    if (_plantedSince + 3.0 - 1.5 < GetTime()) {
        DrawSphere(_position, 0.25f, RED);
    } else {
        DrawSphere(_position, 0.25f, BLACK);
    }
}

void Bomb::destroy()
{
    //destroy
}


