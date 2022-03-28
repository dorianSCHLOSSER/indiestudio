/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** grass
*/

#ifndef GRASS_HPP_
#define GRASS_HPP_
#include "IMap.hpp"

class Grass : public IMap
{
    public:
        Grass(Vector2, Vector3);
        ~Grass() {};

        std::string getName();
        Vector2 getPositionRelative() const;
        Vector3 getPosition() const;
        void setPosition(char, float);
        void setPosition(Vector3);
        void draw();
        void destroy();
    protected:
    private:
        Texture2D _texture;
        Vector3 _position;
        Vector2 _positionRelative;
        const std::string _name;
};

#endif /* !GRASS_HPP_ */
