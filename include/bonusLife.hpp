/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bonusLife
*/

#ifndef BONUSLIFE_HPP_
#define BONUSLIFE_HPP_
#include "IBonus.hpp"

class BonusLife : public IBonus
{
    public:
        BonusLife(Vector2, Vector3);
        ~BonusLife() {}

        std::string getName();
        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
        void setPosition(char, float);
        void setPositionRealtive(Vector2);
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

#endif /* !BONUSLIFE_HPP_ */
