/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bonusBomb
*/

#ifndef BONUSBOMB_HPP_
#define BONUSBOMB_HPP_
#include "IBonus.hpp"

class BonusBomb : public IBonus
{
    public:
        BonusBomb(Vector2, Vector3);
        ~BonusBomb() {}

        std::string getName();
        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
        void setPosition(char, float);
        void setPosition(Vector3);
        void setPositionRealtive(Vector2);
        void draw();
        void destroy();
    protected:
    private:
        Texture2D _texture;
        Vector3 _position;
        Vector2 _positionRelative;
        const std::string _name;
};

#endif /* !BONUSBOMB_HPP_ */
