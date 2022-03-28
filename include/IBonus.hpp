/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** IBonus
*/

#ifndef IBONUS_HPP_
#define IBONUS_HPP_
#include <iostream>
#include <memory>
#include <string>
#include <raylib.h>
#include <map>
#include <fstream>
#include <vector>

class IBonus {
    public:
        virtual Vector3 getPosition() const = 0;
        virtual Vector2 getPositionRelative() const = 0;
        virtual std::string getName() = 0;
        virtual void setPosition(char, float) = 0;
        virtual void setPosition(Vector3) = 0;
        virtual void draw() = 0;
        virtual void destroy() = 0;
        virtual void setPositionRealtive(Vector2) = 0;
    protected:
    private:
};

#endif /* !IBONUS_HPP_ */
