#include "func.h"

void generateWorld(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth)
{
    srand(time(0));

    for (int i = 0; i < gridHeight; i++)
    {
        for (int j = 0; j < gridWidth; j++)
        {
            int randomNum = rand() % 100;
            WORLD[i][j] = (randomNum >= 30 && randomNum <= 40);
        }
    }
}
// void setRules(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth)
// {
//     bool **mirrorWORLD;
//     mirrorWORLD  =new bool*[gridHeight];
//     for(int i=0;i<gridHeight;i++){
//         mirrorWORLD[i] = new bool[gridWidth];
//     }

//     for (int i = 0; i < gridHeight; i++)
//     {
//         for (int j = 0; j < gridWidth; j++)
//         {
//             // Top
//             int cnt = 0;
//             if (i - 1 >= 0)
//             {
//                 if (WORLD[i - 1][j])
//                     cnt++;
//             }
//             if (j - 1 >= 0)
//             {
//                 if (WORLD[i][j - 1])
//                     cnt++;
//             }
//             if (j + 1 < gridWidth)
//             {
//                 if (WORLD[i][j + 1])
//                     cnt++;
//             }
//             if (i + 1 < gridHeight)
//             {
//                 if (WORLD[i + 1][j])
//                     cnt++;
//             }
//             if (cnt > 3)
//             {
//                 mirrorWORLD[i][j] = false;
//             }
//             else if (cnt < 2)
//             {
//                 mirrorWORLD[i][j] = false;
//             }
//             else
//             {
//                 if (!WORLD[i][j])
//                 {
//                     mirrorWORLD[i][j] = true;
//                 }
//                 else
//                 {
//                     if (i - 1 >= 0)
//                     {
//                         if (!WORLD[i - 1][j])
//                         {
//                             mirrorWORLD[i - 1][j] = true;
//                             continue;
//                         }
                            

//                     }
//                     if (j - 1 >= 0)
//                     {
//                         if (!WORLD[i][j - 1])
//                         {
//                             mirrorWORLD[i][j - 1] = true;
//                             continue;
//                         }
                            
//                     }
//                     if (j + 1 < gridWidth)
//                     {
//                         if (!WORLD[i][j + 1])
//                         {
//                             mirrorWORLD[i][j + 1] = 1;
//                             continue;
//                         }
//                     }
//                     if (i + 1 < gridHeight)
//                     {
//                         if (!WORLD[i + 1][j])
//                         {
//                             mirrorWORLD[i + 1][j] = 1;
//                             continue;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     clearWorld(WORLD,gridHeight);
//     WORLD = mirrorWORLD;
// }
void setRules(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth)
{
    bool **mirrorWORLD = new bool*[gridHeight];
    for(int i = 0; i < gridHeight; i++) {
        mirrorWORLD[i] = new bool[gridWidth];
    }

    // Iterate through each cell and apply Game of Life rules
    for (int i = 0; i < gridHeight; i++)
    {
        for (int j = 0; j < gridWidth; j++)
        {
            int cnt = 0;
            
            // Count all 8 neighbors
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0) continue;  // Skip the current cell
                    
                    int ni = i + x;
                    int nj = j + y;
                    
                    if (ni >= 0 && ni < gridHeight && nj >= 0 && nj < gridWidth)
                    {
                        if (WORLD[ni][nj]) cnt++;
                    }
                }
            }
            
            // Apply the rules of Game of Life
            if (WORLD[i][j])  // Cell is alive
            {
                mirrorWORLD[i][j] = (cnt == 2 || cnt == 3);  // Survives if 2 or 3 neighbors
            }
            else  // Cell is dead
            {
                mirrorWORLD[i][j] = (cnt == 3);  // Rebirth if exactly 3 neighbors
            }
        }
    }

    // Clean up the old world and assign the new state
    clearWorld(WORLD, gridHeight);
    WORLD = mirrorWORLD;
}


void display(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth)
{
    // char guys[] = "#";
    // int idx = 0;
    for (int i = 0; i < gridHeight; i++)
    {
        for (int j = 0; j < gridWidth; j++)
        {
            if (WORLD[i][j])
            {
                cout << "#";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}

void clearWorld(bool **&WORLD, const unsigned int gridHeight)
{
    for (int i = 0; i < gridHeight; i++)
    {
        delete[] WORLD[i];
    }
    delete[] WORLD;
}