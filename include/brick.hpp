/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** brick
*/

#ifndef BRICK_HPP_
#define BRICK_HPP_
#include "IMap.hpp"

class Brick : public IMap
{
    public:
        Brick(Vector2, Vector3);
        ~Brick() {};

        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
        Sound getExplosionSound();
        std::string getName();
        void setPosition(char, float);
        void setPosition(Vector3);
        void setExplosionSound(const char *);
        void draw();
        void destroy();
    protected:
    private:
        Texture2D _texture;
        Vector3 _position;
        Vector2 _positionRelative;
        const std::string _name;
        bool _broke;
};

#endif /* !BRICK_HPP_ */