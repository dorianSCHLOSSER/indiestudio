/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** IActor
*/

#ifndef IACTOR_HPP_
#define IACTOR_HPP_
#include <iostream>
#include <memory>
#include <string>
#include <raylib.h>
#include <map>
#include <fstream>
#include <vector>

class IActor {
    public:
        virtual Vector3 getPosition() const = 0;
        virtual Color getColor() const = 0;
        virtual Vector3 getSize() const = 0;
        virtual Vector2 getPositionRelative() const = 0;
        virtual std::string getName() const = 0;
        virtual void setPosition(char, float) = 0;
        virtual void setPositionRelative(Vector2) = 0;
        virtual void setPosition(Vector3) = 0;
        void setLife(int);
        virtual void draw() = 0;
        virtual void moveUp() = 0;
        virtual void moveDown() = 0;
        virtual void moveRight() = 0;
        virtual void moveLeft() = 0;
        virtual int getKeyUp() = 0;
        virtual int getKeyDown() = 0;
        virtual int getKeyLeft() = 0;
        virtual int getKeyRight() = 0;
        virtual int getKeyBomb() = 0;
        virtual int getLife() = 0;
        virtual void setKeys(int, int, int, int, int) = 0;
        virtual void setTouchedSound(const char *) = 0;
        virtual void removeLife() = 0;
        virtual void initHUD(std::string, std::string) = 0;
        virtual Texture2D getLifeHUD() = 0;
        virtual Texture2D getDeathHUD() = 0;
        virtual int getAvailableBombs() = 0;
        virtual Sound getTouchedSound() = 0;
        virtual void removeBombTop() = 0;
};

#endif /* !IACTOR_HPP_ */
