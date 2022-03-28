/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** bigBomb
*/

#ifndef BIGBOMB_HPP_
#define BIGBOMB_HPP_
#include "IBomb.hpp"

class BigBomb : public IBomb
{
    public:
        BigBomb();
        ~BigBomb() {}

        Vector3 getPosition() const;
        Vector2 getPositionRelative() const;
        std::string getName();
        int getRange();
        double getPlantedSince();
        void setPosition(char, float);
        void setPosition(Vector3);
        void setPlantedSince(double);
        void setPositionRelative(Vector2);
        void draw();
        void destroy();
        void setPlanted(bool);
        void setRange(int);
        bool isBeenPlanted();
    protected:
    private:
        Vector3 _position;
        Vector2 _positionRelative;
        const std::string _name;
        bool _planted;
        double _plantedSince;
        int _range;
};

#endif /* !BIGBOMB_HPP_ */
