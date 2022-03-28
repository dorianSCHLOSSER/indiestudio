/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** border
*/

#ifndef BORDER_HPP_
#define BORDER_HPP_
#include "IMap.hpp"

class Border : public IMap
{
    public:
        Border(Vector2, Vector3);
        ~Border() {};

        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
        std::string getName();
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

#endif /* !BODER_HPP_ */