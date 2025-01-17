#ifndef GROUND_HPP
#define GROUND_HPP

// #include "game.hpp"

// class Game;

class Ground
{
public:
    // Ground(int w, int h);
    // Ground(int gridWidth = 40, int gridHeight = 20);
    Ground(int w, int h) : gridWidth(w), gridHeight(h) {}

    void drawGround();

private:
    const int gridWidth;
    const int gridHeight;
    // int width = gridWidth;
    // int height = gridHeight;
    // const int gridWidth = 40;
    // const int gridHeight = 20;
};

#endif // GROUND_HPP
