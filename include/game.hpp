/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#include <cstdlib>
#include "actor.hpp"
#include "border.hpp"
#include "wall.hpp"
#include "grass.hpp"
#include "brick.hpp"
#include "bomb.hpp"
#include "bonusBomb.hpp"
#include "bonusLife.hpp"
#include "bigBomb.hpp"

class Game
{
    public:
        Game();
        ~Game() {}

        std::map<int, std::string> getMainMap();
        void parseMap();
        void drawGame();
        void destroy();
        void initNewGame(int);
        void initLoadGame();
        void loopGame();
        void commandsPlayer();
        bool checkComponentUp(int, std::string);
        bool checkComponentDown(int, std::string);
        bool checkComponentLeft(int, std::string);
        bool checkComponentRight(int, std::string);
        bool _checkBombsActors(std::shared_ptr<Actor>, std::shared_ptr<IBomb>, int);
        void checkBombsActors(std::vector<std::shared_ptr<Actor>>, std::shared_ptr<IBomb>);
        void checkIBombs();
        bool isTouchedLeft(Vector2, std::shared_ptr<IBomb>);
        bool isTouchedRight(Vector2, std::shared_ptr<IBomb>);
        bool isTouchedUp(Vector2, std::shared_ptr<IBomb>);
        bool isTouchedDown(Vector2, std::shared_ptr<IBomb>);
        void brokeBrick(std::shared_ptr<IBomb>);
        bool checkBrokeLeft(std::shared_ptr<IBomb>);
        bool checkBrokeRight(std::shared_ptr<IBomb>);
        bool checkBrokeUp(std::shared_ptr<IBomb>);
        bool checkBrokeDown(std::shared_ptr<IBomb>);
        bool checkPositionisBeenplanted(std::shared_ptr<Actor>);
        void initBackground();
        void initSounds();
        void draw2DHUD();
        void createBonus(std::shared_ptr<IMap>);
        void checkIBonus();
        void _checkIBonus(std::vector<std::shared_ptr<Actor>>);
        void checkFinal();
    private:
        std::vector<std::shared_ptr<Actor>> _bots;
        std::vector<std::shared_ptr<Actor>> _players;
        std::vector<std::shared_ptr<IMap>> _map;
        std::vector<std::shared_ptr<IBonus>> _bonus;
        std::string _mapPath;
        double _bombLifeTime;
        Texture2D _background;
        Sound _brickExplosionSound;
        Sound _bombExplosionSound;
        Sound _bonusLifeSound;
        Sound _bonusBombSound;
};

#endif /* !GAME_HPP_ */
