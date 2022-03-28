/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** game.cpp
*/

#include "../../include/game.hpp"

Game::Game() : _mapPath("../maps/main_map.txt"), _bombLifeTime(2) {}

std::map<int, std::string> Game::getMainMap()
{
    std::map<int, std::string> mainMap;
    std::ifstream file;
    file.open(_mapPath);
    std::string line;

    for (int horizontal = 0 ; horizontal < 13 ; horizontal++) {
        std::getline(file, line);
        mainMap[horizontal] = line;
    }
    return (mainMap);
}

void Game::initBackground()
{
    _background = LoadTexture("../resources/background.png");
}

void Game::initSounds()
{
    _brickExplosionSound = LoadSound("../resources/sounds/brick.ogg");
    _bombExplosionSound = LoadSound("../resources/sounds/bomb.ogg");
    _bonusBombSound = LoadSound("../resources/sounds/bonus-bomb.ogg");
    _bonusLifeSound = LoadSound("../resources/sounds/bonus-life.ogg");
}

void Game::parseMap()
{
    std::map<int, std::string> mainMap = getMainMap();

    for (int vertical = 0; vertical < 13; vertical++) {
        for (int horizontal = 0 ; horizontal < 19; horizontal++) {
            if (mainMap[vertical][horizontal] == 'x') {
                std::shared_ptr<Border> newBorder = std::make_shared<Border>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    0.0f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newBorder));
            }
            else if (mainMap[vertical][horizontal] == '*') {
                std::shared_ptr<Grass> newGrass = std::make_shared<Grass>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    -0.5f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newGrass));
            }
            else if (mainMap[vertical][horizontal] == 'O') {
                std::shared_ptr<Wall> newWall = std::make_shared<Wall>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    0.0f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newWall));
            }
            else if (mainMap[vertical][horizontal] == '1') {
                std::shared_ptr<Actor> newPlayer = std::make_shared<Actor>(
                    YELLOW,
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f), 0.0f, (float)(vertical - 8.0f)},
                    (Vector3){0.5f, 3.0f, 0.5f},
                    "player");
                newPlayer->setKeys(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE);
                newPlayer->initHUD("../resources/hud-player-1.png", "../resources/hud-player-die-1.png");
                newPlayer->setTouchedSound("../resources/sounds/ouch.ogg");
                std::shared_ptr<Grass> newGrass = std::make_shared<Grass>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    -0.5f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newGrass));
                _players.insert(_players.begin(), std::move(newPlayer));
            }
            else if (mainMap[vertical][horizontal] == '2') {
                std::shared_ptr<Actor> newPlayer = std::make_shared<Actor>(
                    PURPLE,
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f), 0.0f, (float)(vertical - 8.0f)},
                    (Vector3){0.5f, 3.0f, 0.5f},
                    "player");
                newPlayer->setKeys(KEY_E, KEY_D, KEY_S, KEY_F, KEY_G);
                newPlayer->initHUD("../resources/hud-player-2.png", "../resources/hud-player-die-2.png");
                newPlayer->setTouchedSound("../resources/sounds/ouch.ogg");
                std::shared_ptr<Grass> newGrass = std::make_shared<Grass>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    -0.5f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newGrass));
                _players.push_back(std::move(newPlayer));
            }
            else if (mainMap[vertical][horizontal] == 'B') {
                std::shared_ptr<Actor> newBot = std::make_shared<Actor>(
                    RED,
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f), 0.0f, (float)(vertical - 8.0f)},
                    (Vector3){0.5f, 3.0f, 0.5f},
                    "bot");
                newBot->initHUD("../resources/hud-bot.png", "../resources/hud-bot-die.png");
                newBot->setTouchedSound("../resources/sounds/ouch.ogg");
                std::shared_ptr<Grass> newGrass = std::make_shared<Grass>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    -0.5f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newGrass));
                _bots.push_back(std::move(newBot));
            }
            else if (mainMap[vertical][horizontal] == 'k') {
                std::shared_ptr<Brick> newBrick = std::make_shared<Brick>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    0.0f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newBrick));
                std::shared_ptr<Grass> newGrass = std::make_shared<Grass>(
                    (Vector2){(float)horizontal, (float)vertical},
                    (Vector3){(float)(horizontal - 9.0f),
                    -0.5f,
                    (float)(vertical - 8.0f)});
                _map.push_back(std::move(newGrass));
            }
        }
    }
}

void Game::drawGame()
{
    DrawCubeTexture(_background, (Vector3){0.0f, -0.6f, 0.0f}, 38.0f, 0.0f, 38.0f, WHITE);
    for (const auto &component : _map) {
        component->draw();
    }
    for (const auto &bonus : _bonus) {
        bonus->draw();
    }
    for (const auto &player : _players) {
        player->draw();
    }
    for (const auto &bot : _bots) {
        bot->draw();
    }
    for (auto &player : _players) {
        for (auto &bomb : player->getBombs()) {
            if (bomb->isBeenPlanted() == true) {
                bomb->draw();
            }
        }
    }
}

void Game::destroy()
{
    for (const auto &component : _map) {
            component->destroy();
    }
}

void Game::initNewGame(int numberOfPlayers)
{
    // generate_new_game(numberOfPlayers);
    // parseMap();
    // loopGame()
}

void Game::initLoadGame()
{}

void Game::loopGame()
{}

bool Game::checkComponentUp(int nbPlayer, std::string componentName)
{
    for (auto &map : _map) {
        if (_players[nbPlayer]->getPositionRelative().x == map->getPositionRelative().x && _players[nbPlayer]->getPositionRelative().y - 1 == map->getPositionRelative().y) {
            if (map->getName() == componentName) {
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkComponentDown(int nbPlayer, std::string componentName)
{
    for (auto &map : _map) {
        if (_players[nbPlayer]->getPositionRelative().x == map->getPositionRelative().x && _players[nbPlayer]->getPositionRelative().y + 1 == map->getPositionRelative().y) {
            if (map->getName() == componentName) {
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkComponentLeft(int nbPlayer, std::string componentName)
{
    for (auto &map : _map) {
        if (_players[nbPlayer]->getPositionRelative().x - 1 == map->getPositionRelative().x && _players[nbPlayer]->getPositionRelative().y == map->getPositionRelative().y) {
            if (map->getName() == componentName) {
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkComponentRight(int nbPlayer, std::string componentName)
{
    for (auto &map : _map) {
        if (_players[nbPlayer]->getPositionRelative().x + 1 == map->getPositionRelative().x && _players[nbPlayer]->getPositionRelative().y == map->getPositionRelative().y) {
            if (map->getName() == componentName) {
                return (true);
            }
        }
    }
    return (false);
}

bool Game::isTouchedLeft(Vector2 position, std::shared_ptr<IBomb> bomb)
{
    for (auto &component : _map) {
        for (int i = bomb->getPositionRelative().x - 1; i > position.x; i--) {
            if ((component->getName() == "wall" || component->getName() == "brick") &&
                component->getPositionRelative().x == i &&
                component->getPositionRelative().y == bomb->getPositionRelative().y)
                return (false);
        }
    }
    return (true);
}

bool Game::isTouchedRight(Vector2 position, std::shared_ptr<IBomb>bomb)
{
    for (auto &component : _map) {
        for (int i = bomb->getPositionRelative().x + 1; i < position.x; i++) {
            if ((component->getName() == "wall" || component->getName() == "brick") &&
                component->getPositionRelative().x == i &&
                component->getPositionRelative().y == bomb->getPositionRelative().y)
                return (false);
        }
    }
    return (true);
}

bool Game::isTouchedUp(Vector2 position, std::shared_ptr<IBomb> bomb)
{
    for (auto &component : _map) {
        for (int i = bomb->getPositionRelative().y - 1; i > position.y; i--) {
            if ((component->getName() == "wall" || component->getName() == "brick") &&
                component->getPositionRelative().y == i &&
                component->getPositionRelative().x == bomb->getPositionRelative().x)
                return (false);
        }
    }
    return (true);
}

bool Game::isTouchedDown(Vector2 position, std::shared_ptr<IBomb> bomb)
{
    for (auto &component : _map) {
        for (int i = bomb->getPositionRelative().y + 1; i < position.y; i++) {
            if ((component->getName() == "wall" || component->getName() == "brick") &&
                component->getPositionRelative().y == i &&
                component->getPositionRelative().x == bomb->getPositionRelative().x)
                return (false);
        }
    }
    return (true);
}

bool Game::_checkBombsActors(std::shared_ptr<Actor> actor, std::shared_ptr<IBomb> bomb, int i)
{
    if (actor->getPositionRelative().x == bomb->getPositionRelative().x - i &&
        actor->getPositionRelative().y == bomb->getPositionRelative().y &&
        isTouchedLeft(actor->getPositionRelative(), bomb) == true) {
        return (true);
    }
    if (actor->getPositionRelative().x == bomb->getPositionRelative().x + i &&
        actor->getPositionRelative().y == bomb->getPositionRelative().y &&
        isTouchedRight(actor->getPositionRelative(), bomb) == true) {
        return (true);
    }
    if (actor->getPositionRelative().x == bomb->getPositionRelative().x &&
        actor->getPositionRelative().y == bomb->getPositionRelative().y - i &&
        isTouchedUp(actor->getPositionRelative(), bomb) == true) {
        return (true);
    }
    if (actor->getPositionRelative().x == bomb->getPositionRelative().x &&
        actor->getPositionRelative().y == bomb->getPositionRelative().y + i &&
        isTouchedDown(actor->getPositionRelative(), bomb) == true) {
        return (true);
    }
    return (false);
}

void Game::checkBombsActors(std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<IBomb> bomb)
{
    for (auto &actor : actors) {
        for (int i = 0 ; i <= bomb->getRange() ; i++) {
            if (_checkBombsActors(actor, bomb, i)) {
                if (actor->getLife() > 0) {
                    PlaySound(actor->getTouchedSound());
                }
                actor->removeLife();
                break;
            }
        }
    }
}

void Game::createBonus(std::shared_ptr<IMap> component)
{
    int randm = rand() % 4;
    if (randm == 2) {
        randm = rand() % 2 + 1;
        if (randm == 1) {
            Vector3 position = component->getPosition();
            position.y = 0.1f;
            std::shared_ptr<BonusLife> newLife = std::make_shared<BonusLife>(component->getPositionRelative(), position);
            _bonus.push_back(std::move(newLife));
        }
        else {
            Vector3 position = component->getPosition();
            position.y = 0.1f;
            std::shared_ptr<BonusBomb> newBonus = std::make_shared<BonusBomb>(component->getPositionRelative(), position);
            _bonus.push_back(std::move(newBonus));
        }
    }
}

bool Game::checkBrokeLeft(std::shared_ptr<IBomb> bomb)
{
    for (int i = bomb->getPositionRelative().x ; i > (bomb->getPositionRelative().x - bomb->getRange() - 1) ; i--) {
        for (auto &component : _map) {
            if (component->getName() == "brick" &&
                component->getPositionRelative().x == i &&
                component->getPositionRelative().y == bomb->getPositionRelative().y &&
                isTouchedLeft(component->getPositionRelative(), bomb) == true) {
                createBonus(component);
                component->destroy();
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkBrokeRight(std::shared_ptr<IBomb> bomb)
{
    for (int i = bomb->getPositionRelative().x ; i < (bomb->getPositionRelative().x + bomb->getRange() + 1) ; i++) {
        for (auto &component : _map) {
            if (component->getName() == "brick" &&
                component->getPositionRelative().x == i &&
                component->getPositionRelative().y == bomb->getPositionRelative().y &&
                isTouchedRight(component->getPositionRelative(), bomb) == true) {
                createBonus(component);
                component->destroy();
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkBrokeUp(std::shared_ptr<IBomb> bomb)
{
    for (int i = bomb->getPositionRelative().y ; i > (bomb->getPositionRelative().y - bomb->getRange() - 1) ; i--) {
        for (auto &component : _map) {
            if (component->getName() == "brick" &&
                component->getPositionRelative().y == i &&
                component->getPositionRelative().x == bomb->getPositionRelative().x &&
                isTouchedUp(component->getPositionRelative(), bomb) == true) {
                createBonus(component);
                component->destroy();
                return (true);
            }
        }
    }
    return (false);
}

bool Game::checkBrokeDown(std::shared_ptr<IBomb> bomb)
{
    for (int i = bomb->getPositionRelative().y ; i < (bomb->getPositionRelative().y + bomb->getRange() + 1) ; i++) {
        for (auto &component : _map) {
            if (component->getName() == "brick" &&
                component->getPositionRelative().y == i &&
                component->getPositionRelative().x == bomb->getPositionRelative().x &&
                isTouchedDown(component->getPositionRelative(), bomb) == true) {
                createBonus(component);
                component->destroy();
                return (true);
            }
        }
    }
    return (false);
}

void Game::brokeBrick(std::shared_ptr<IBomb> bomb)
{
    bool playSound = false;

    if (checkBrokeLeft(bomb)) playSound = true;
    if (checkBrokeRight(bomb)) playSound = true;
    if (checkBrokeUp(bomb)) playSound = true;;
    if (checkBrokeDown(bomb))  playSound = true;
    if (playSound) PlaySound(_brickExplosionSound);
}

void Game::checkIBombs()
{
    for (auto &player : _players) {
        for (auto &bomb : player->getBombs()) {
            if (bomb->getPlantedSince() + _bombLifeTime < GetTime() && bomb->isBeenPlanted() == true) {
                PlaySound(_bombExplosionSound);
                bomb->setPlanted(false);
                checkBombsActors(_players, bomb);
                checkBombsActors(_bots, bomb);
                brokeBrick(bomb);
                if (bomb->getName() == "bigBomb") player->removeBombTop();
            }
        }
    }
    for (auto &bot : _bots) {
        for (auto &bomb : bot->getBombs()) {
            if (bomb->getPlantedSince() + _bombLifeTime < GetTime() && bomb->isBeenPlanted() == true) {
                PlaySound(_bombExplosionSound);
                bomb->setPlanted(false);
                checkBombsActors(_bots, bomb);
                checkBombsActors(_players, bomb);
                brokeBrick(bomb);
                if (bomb->getName() == "bigBomb") bot->removeBombTop();
            }
        }
    }
}

bool Game::checkPositionisBeenplanted(std::shared_ptr<Actor> actor)
{
    for (auto &bomb : actor->getBombs()) {
        if (bomb->isBeenPlanted() == true &&
        actor->getPositionRelative().x == bomb->getPositionRelative().x &&
        actor->getPositionRelative().y == bomb->getPositionRelative().y) {
        return (false);
        }
    }
    return (true);
}

void Game::commandsPlayer()
{
    int i = 0;
    for (auto &player : _players) {
        if (IsKeyPressed(player->getKeyRight())) {
            if (checkComponentRight(i, "grass") == true && checkComponentRight(i, "brick") == false) player->moveRight();
        }
        if (IsKeyPressed(player->getKeyLeft())) {
            if (checkComponentLeft(i, "grass") == true && checkComponentLeft(i, "brick") == false) player->moveLeft();
        }
        if (IsKeyPressed(player->getKeyDown())) {
            if (checkComponentDown(i, "grass") == true && checkComponentDown(i, "brick") == false) player->moveDown();
        }
        if (IsKeyPressed(player->getKeyUp())) {
            if (checkComponentUp(i, "grass") == true && checkComponentUp(i, "brick") == false) player->moveUp();
        }
        if (IsKeyPressed(player->getKeyBomb())) {
            for (auto &bomb : player->getBombs()) {
                if (bomb->isBeenPlanted() == false && checkPositionisBeenplanted(player) == true) {
                    bomb->setPosition(player->getPosition());
                    bomb->setPositionRelative(player->getPositionRelative());
                    bomb->setPlanted(true);
                    bomb->setPlantedSince(GetTime());
                    break;
                }
            }
        }
        i += 1;
    }
}

void Game::draw2DHUD()
{
    int posX = 100;
    int posY = 690;
    for (auto &player : _players) {
        if (player->getLife() <= 0) {
            DrawTexture(player->getDeathHUD(), posX, posY, WHITE);
        } else {
            DrawTexture(player->getLifeHUD(), posX, posY, WHITE);
        }
        std::string remainingLife = std::to_string(player->getLife());
        std::string remainingBombs = std::to_string(player->getAvailableBombs());
        DrawText(remainingLife.c_str(), posX + 300, posY + 63, 40, WHITE);
        DrawText(remainingBombs.c_str(), posX + 300, posY + 127, 40, WHITE);
        posX += 400;
    }
    for (auto &bot : _bots) {
        if (bot->getLife() <= 0) {
            DrawTexture(bot->getDeathHUD(), posX, posY, WHITE);
        } else {
            DrawTexture(bot->getLifeHUD(), posX, posY, WHITE);
        }
        std::string remainingLife = std::to_string(bot->getLife());
        std::string remainingBombs = std::to_string(bot->getAvailableBombs());
        DrawText(remainingLife.c_str(), posX + 300, posY + 63, 40, WHITE);
        DrawText(remainingBombs.c_str(), posX + 300, posY + 127, 40, WHITE);
        posX += 400;
    }
}

void Game::_checkIBonus(std::vector<std::shared_ptr<Actor>> actor)
{
    for (auto &player : _players) {
        for (auto &bonus : _bonus) {
            if (player->getPositionRelative().x == bonus->getPositionRelative().x &&
                player->getPositionRelative().y == bonus->getPositionRelative().y) {
                if (bonus->getName() == "bonusBomb") {
                    std::shared_ptr<BigBomb> newBigBomb = std::make_shared<BigBomb>();
                    player->addBomb(newBigBomb);
                    PlaySound(_bonusBombSound);
                    bonus->destroy();
                    break;
                }
                if (bonus->getName() == "bonusLife") {
                    player->addLife();
                    PlaySound(_bonusLifeSound);
                    bonus->destroy();
                    break;
                }
            }
        }
    }
}

void Game::checkIBonus()
{
    _checkIBonus(_players);
    _checkIBonus(_bots);
}

void Game::checkFinal()
{
    int count = 0;
    for (auto &player : _players) {
        if (player->getLife() <= 0) count += 1;
    }
    if (count == 2) {
        ClearBackground(RAYWHITE);
        DrawText("END GAME", 740, 380, 60, BLACK);
        DrawText("Press ECHAP to exit the game !", 700, 490, 30, BLACK);
    }
}