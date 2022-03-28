/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** actor
*/

#ifndef ACTOR_HPP_
#define ACTOR_HPP_
#include "IActor.hpp"
#include "bomb.hpp"

class Actor : public IActor
{
    public:
        Actor(Color, Vector2, Vector3, Vector3, std::string);
        ~Actor() {};

        std::string getName() const;
        Vector3 getPosition() const;
        Color getColor() const;
        Vector3 getSize() const;
        Vector2 getPositionRelative() const;
        void setKeys(int, int, int, int, int);
        void setPosition(char, float);
        void setPosition(Vector3);
        void setPositionRelative(Vector2);
        void setLife(int);
        void setTouchedSound(const char *);
        void removeLife();
        void draw();
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        int getKeyUp();
        int getKeyDown();
        int getKeyLeft();
        int getKeyRight();
        int getKeyBomb();
        int getLife();
        Sound getTouchedSound();
        std::vector<std::shared_ptr<IBomb>> getBombs();
        void initHUD(std::string, std::string);
        Texture2D getLifeHUD();
        Texture2D getDeathHUD();
        int getAvailableBombs();
        void addBomb(std::shared_ptr<IBomb>);
        void removeBombTop();
        void addLife();
    protected:
    private:
        Color _color;
        Vector2 _positionRelative;
        Vector3 _position;
        Vector3 _size;
        std::string _name;
        int _key_up;
        int _key_down;
        int _key_left;
        int _key_right;
        int _key_bomb;
        std::vector<std::shared_ptr<IBomb>> _bombs;
        int _life;
        Texture2D _life_hud;
        Texture2D _death_hud;
        Sound _touchedSound;
};

#endif /* !ACTOR_HPP_ */