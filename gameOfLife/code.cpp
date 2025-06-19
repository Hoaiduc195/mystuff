#include "func.h"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const unsigned int gridHeight = 30;
    const unsigned int gridWidth = 120;
    bool **WORLD;
    WORLD = new bool *[gridHeight];
    for (int i = 0; i < gridHeight; i++)
    {
        WORLD[i] = new bool[gridWidth];
    }
    generateWorld(WORLD,gridHeight,gridWidth);
    while (true)
    {
        setRules(WORLD,gridHeight,gridWidth);
        display(WORLD,gridHeight,gridWidth);
        Sleep(300);
        system("clear");
    }

    return 0;
}