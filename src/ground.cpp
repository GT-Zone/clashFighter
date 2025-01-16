#include <iostream>
#include <ncurses.h>

using namespace std;

class Ground
{
private:
    int width;
    int height;

public:
    Ground(int w, int h) : width(w), height(h) {}
    void initScreen()
    {
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        start_color();

        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_CYAN, COLOR_BLACK);
    }
    void drawGround()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || i == height - 1)
                {
                    attron(COLOR_PAIR(4));
                    printw("- ");
                    attroff(COLOR_PAIR(4));
                }
                else if (j == 0 || j == width - 1)
                {
                    attron(COLOR_PAIR(4));
                    printw("| ");
                    attroff(COLOR_PAIR(4));
                }
                else
                {
                    attron(COLOR_PAIR(2));
                    printw(". ");
                    attroff(COLOR_PAIR(2));
                }
            }
            printw("\n");
        }
    }
    void endScreen()
    {
        getch();
        endwin();
    }
};
