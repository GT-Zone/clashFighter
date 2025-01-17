#include "game.hpp"
#include "ground.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include <chrono> // For std::chrono::milliseconds
#include <thread> // For std::this_thread::sleep_for

Game::Game() : isRunning(true), ground(gridWidth, gridHeight)
{

    // Initialize ncurses
    initscr();
    if (!has_colors())
    {
        endwin();
        std::cerr << "Your terminal does not support color." << std::endl;
        exit(1);
    }
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // Non-blocking input
    curs_set(0);           // Hide the cursor

    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    //  if (gridWidth * 2 > termWidth || gridHeight > termHeight)
    // {
    //     endwin();
    //     std::cerr << "Error: Terminal size too small for the grid.\n";
    //     exit(1);
    // }
    mvprintw(0, 0, "Game Starting..."); // Debugging info
    refresh();
}

void Game::run()
{
    const auto FpsCount = std::chrono::milliseconds(1000 / 30);

    const auto HeroSpeed = std::chrono::milliseconds(100);

    auto lastMoveTime = std::chrono::high_resolution_clock::now();

    while (isRunning)
    {
        auto frameStart = std::chrono::high_resolution_clock::now();
        userControl();

        auto now = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMoveTime);

        if (elapsedTime >= HeroSpeed)
        {
            update();           // Move the Hero
            lastMoveTime = now; // Reset the last move time
        }
        render();

        auto frameEnd = std::chrono::high_resolution_clock::now();
        auto frameDuration = frameEnd - frameStart;
        if (frameDuration < FpsCount)
        {
            std::this_thread::sleep_for(FpsCount - frameDuration);
        }
    }
}

void Game::userControl()
{
    // int ch = wgetch(stdscr); // Get the pressed key

    // switch (ch)
    // {
    // case KEY_UP:
    //     if (directionY == 0)
    //     { // Prevent reversing direction
    //         directionX = 0;
    //         directionY = -1;
    //     }
    //     break;
    // case KEY_DOWN:
    //     if (directionY == 0)
    //     {
    //         directionX = 0;
    //         directionY = 1;
    //     }
    //     break;
    // case KEY_LEFT:
    //     if (directionX == 0)
    //     {
    //         directionX = -1;
    //         directionY = 0;
    //     }
    //     break;
    // case KEY_RIGHT:
    //     if (directionX == 0)
    //     {
    //         directionX = 1;
    //         directionY = 0;
    //     }
    //     break;
    // case 'q': // Quit the game
    //     isRunning = false;
    //     break;
    // default:
    //     break;
    // }

    int ch = getch(); // Get the pressed key (using getch for simplicity)

    if (ch == ERR)
        return; // No input, return immediately

    switch (ch)
    {
    case KEY_UP:
        if (directionY == 0) // Prevent reversing direction
        {
            directionX = 0;
            directionY = -1;
        }
        break;
    case KEY_DOWN:
        if (directionY == 0)
        {
            directionX = 0;
            directionY = 1;
        }
        break;
    case KEY_LEFT:
        if (directionX == 0)
        {
            directionX = -1;
            directionY = 0;
        }
        break;
    case KEY_RIGHT:
        if (directionX == 0)
        {
            directionX = 1;
            directionY = 0;
        }
        break;
    case 'q': // Quit the game
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
}

void Game::render()
{
    clear(); // Clears the screen

    ground.drawGround();
    mvprintw(gridHeight + 1, 0, "Press 'q' to quit.");

    refresh(); // Refresh to update the display
}

Game::~Game()
{
    endwin(); // Clean up ncurses
}