// #include "game.hpp"
#include "ground.hpp"

// #include <iostream>
#include <ncurses.h>

// void Ground::drawGround()
// {
//     for (int i = 0; i < gridHeight; i++)
//     {
//         for (int j = 0; j < gridWidth; j++)
//         {
//             if (i == 0 || i == gridHeight - 1) // Top and bottom borders
//             {
//                 attron(COLOR_PAIR(4));
//                 mvprintw(i, j * 2, "-"); // Position horizontally at (i, j * 2)
//                 attroff(COLOR_PAIR(4));
//             }
//             else if (j == 0 || j == gridWidth - 1) // Left and right borders
//             {
//                 attron(COLOR_PAIR(4));
//                 mvprintw(i, j * 2, "|"); // Vertical boundary
//                 attroff(COLOR_PAIR(4));
//             }
//             else // Inner cells
//             {
//                 attron(COLOR_PAIR(2));
//                 mvprintw(i, j * 2, "."); // Interior grid
//                 attroff(COLOR_PAIR(2));
//             }
//         }
//     }

//     refresh(); // Refresh to update the display
// }

void Ground::drawGround()
{
    for (int i = 0; i < gridHeight; i++)
    {
        for (int j = 0; j < gridWidth; j++)
        {
            if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1) // Borders
            {
                attron(COLOR_PAIR(4));
                mvprintw(i, j * 2, "|"); // Borders
                attroff(COLOR_PAIR(4));
            }
            else // Inner grid
            {
                attron(COLOR_PAIR(2));
                mvprintw(i, j * 2, "."); // Empty inner space
                attroff(COLOR_PAIR(2));
            }
        }
    }
    refresh(); // Ensure changes are displayed
}

// using namespace std;

// Ground::Ground(int w, int h) : gridWidth(w), gridHeight(h) {}

// class Ground
// {
// private:
//     int width;
//     int height;

// public:
// Ground(int w, int h) : width(w), height(h) ;
//     void initScreen()
//     {
//         initscr();
//         cbreak();
//         noecho();
//         curs_set(0);
//         start_color();

//         init_pair(1, COLOR_RED, COLOR_BLACK);
//         init_pair(2, COLOR_GREEN, COLOR_BLACK);
//         init_pair(4, COLOR_CYAN, COLOR_BLACK);
//     }

// void endScreen()
// {
//     getch();
//     endwin();
// }
