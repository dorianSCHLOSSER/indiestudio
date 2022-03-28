/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** actor.cpp
*/

#include "../../include/actor.hpp"

Actor::Actor(Color color, Vector2 positionRelative, Vector3 position, Vector3 playerSize, std::string name)
{
    _name = name;
    _color = color;
    _positionRelative = positionRelative;
    _position = position;
    _size = playerSize;
    _life = 2;

    for (int i = 0; i < 2; i++) {
        std::shared_ptr<Bomb> bomb = std::make_shared<Bomb>();
        _bombs.push_back(std::move(bomb));
    }
}

std::string Actor::getName() const
{
    return (_name);
}

int Actor::getKeyUp()
{
    return (_key_up);
}

int Actor::getKeyDown()
{
    return (_key_down);
}

int Actor::getKeyLeft()
{
    return (_key_left);
}

int Actor::getKeyRight()
{
    return (_key_right);
}

int Actor::getKeyBomb()
{
    return (_key_bomb);
}

int Actor::getLife()
{
    return (_life);
}

Vector3 Actor::getPosition() const
{
    return (_position);
}


Color Actor::getColor() const
{
    return (_color);
}

Vector2 Actor::getPositionRelative() const
{
    return (_positionRelative);
}

Vector3 Actor::getSize() const
{
    return (_size);
}

std::vector<std::shared_ptr<IBomb>> Actor::getBombs()
{
    return (_bombs);
}

int Actor::getAvailableBombs()
{
    int count = 0;

    for (auto &bomb : _bombs) {
        if (!bomb->isBeenPlanted()) {
            count += 1;
        }
    }
    return (count);
}

Sound Actor::getTouchedSound()
{
    return (_touchedSound);
}

void Actor::setTouchedSound(const char *soundPath)
{
    _touchedSound = LoadSound(soundPath);
}

void Actor::setKeys(int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb)
{
    _key_up = keyUp;
    _key_down = keyDown;
    _key_left = keyLeft;
    _key_right = keyRight;
    _key_bomb = keyBomb;
}

void Actor::setPosition(char position, float number)
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

void Actor::setPosition(Vector3 position)
{
    _position = position;
}

void Actor::setPositionRelative(Vector2 rel)
{
    _positionRelative.x += rel.x;
    _positionRelative.y += rel.y;
}

void Actor::setLife(int life)
{
    _life = life;
}

void Actor::removeLife()
{
    if (_life > 0) {
        _life -= 1;
    }
}

void Actor::draw()
{
    if (_life > 0) {
        DrawCubeV(getPosition(), getSize(), getColor());
    }
    else {
        _bombs.clear();
    }
}

void Actor::moveUp()
{
    setPositionRelative((Vector2){0, -1});
    setPosition('z', (-1.0f));
}

void Actor::moveDown()
{
    setPositionRelative((Vector2){0, 1});
    setPosition('z', 1.0f);
}

void Actor::moveLeft()
{
    setPositionRelative((Vector2){-1, 0});
    setPosition('x', (-1.0f));
}

void Actor::moveRight()
{
    setPositionRelative((Vector2){1, 0});
    setPosition('x', 1.0f);
}

void Actor::initHUD(std::string lifeHUD, std::string deathHUD)
{
    _life_hud = LoadTexture(lifeHUD.c_str());
    _death_hud = LoadTexture(deathHUD.c_str());
}

Texture2D Actor::getLifeHUD()
{
    return (_life_hud);
}

Texture2D Actor::getDeathHUD()
{
    return (_death_hud);
}

void Actor::addBomb(std::shared_ptr<IBomb> bomb)
{
    _bombs.insert(_bombs.begin(), std::move(bomb));
}

void Actor::removeBombTop()
{
    _bombs.erase(_bombs.begin());
}

void Actor::addLife()
{
    _life += 1;
}
