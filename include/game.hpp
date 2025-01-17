#ifndef GAME_HPP
#define GAME_HPP
#include "ground.hpp"
#include <utility>
class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void userControl();
    void update();
    void render();

    Ground ground;

    bool isRunning;

    const int gridWidth = 40;
    const int gridHeight = 20;

    int directionX = 0; // Hero's current horizontal direction
    int directionY = 0; // Hero's current vertical direction
};
#endif
