/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** IBomb
*/

#ifndef IBOMB_HPP_
#define IBOMB_HPP_
#include <iostream>
#include <memory>
#include <string>
#include <raylib.h>
#include <map>
#include <fstream>
#include <vector>

class IBomb {
    public:
        virtual Vector3 getPosition() const = 0;
        virtual Vector2 getPositionRelative() const = 0;
        virtual std::string getName() = 0;
        virtual double getPlantedSince() = 0;
        virtual int getRange() = 0;
        virtual void setPosition(char, float) = 0;
        virtual void setPosition(Vector3) = 0;
        virtual void setPlanted(bool) = 0;
        virtual void setPlantedSince(double) = 0;
        virtual void draw() = 0;
        virtual void destroy() = 0;
        virtual bool isBeenPlanted() = 0;
        virtual void setPositionRelative(Vector2) = 0;
};

#endif /* !IBOMB_HPP_ */
