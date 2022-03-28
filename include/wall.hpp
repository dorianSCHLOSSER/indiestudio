/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_
#include "IMap.hpp"

class Wall : public IMap
{
    public:
        Wall(Vector2, Vector3);
        ~Wall() {}

        std::string getName();
        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
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

#endif /* !WALL_HPP_ */