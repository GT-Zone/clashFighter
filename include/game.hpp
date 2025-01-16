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
    void processInput();
    void update();
    bool isRunning;

    const int gridWidth = 30;
    const int gridHeight = 30;
};
#endif
