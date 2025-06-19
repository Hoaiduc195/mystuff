#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>  // For sleep function (Linux/Mac). Use <Windows.h> and Sleep() for Windows.

using namespace std;

// Function to create a grid
bool **createGrid(int height, int width) {
    bool **grid = new bool*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new bool[width]{false};
    }
    return grid;
}

// Function to clear a grid (deallocate memory)
void clearGrid(bool **grid, int height) {
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Function to initialize the grid with random values
void initializeGrid(bool **grid, int height, int width) {
    srand(time(nullptr));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;  // Randomly set cells to alive or dead
        }
    }
}

// Display the grid
void displayGrid(bool **grid, int height, int width) {
    system("clear");  // For Linux/Mac. Use "cls" for Windows.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << (grid[i][j] ? "#" : " ");
        }
        cout << endl;
    }
    cout << endl;
}

// Apply Game of Life rules
void setRules(bool **&grid, int height, int width) {
    bool **nextGrid = createGrid(height, width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = 0;

            // Count neighbors (including diagonals)
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;  // Skip the current cell
                    
                    int ni = i + x;
                    int nj = j + y;

                    // Check boundaries
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
                        if (grid[ni][nj]) neighbors++;
                    }
                }
            }

            // Apply Game of Life rules
            if (grid[i][j]) {  // If cell is alive
                nextGrid[i][j] = (neighbors == 2 || neighbors == 3);
            } else {  // If cell is dead
                nextGrid[i][j] = (neighbors == 3);
            }
        }
    }

    // Swap grids and clear the old one
    clearGrid(grid, height);
    grid = nextGrid;
}

// Main loop to run the simulation
void runGame(int height, int width, int iterations, int delay) {
    bool **grid = createGrid(height, width);
    initializeGrid(grid, height, width);

    for (int i = 0; i < iterations; i++) {
        displayGrid(grid, height, width);
        setRules(grid, height, width);
        usleep(delay * 1000);  // Delay in milliseconds
    }

    clearGrid(grid, height);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int height = 30;
    int width = 120;
    int iterations = 100;
    int delay = 100;  // Delay between generations in milliseconds

    runGame(height, width, iterations, delay);
    return 0;
}
