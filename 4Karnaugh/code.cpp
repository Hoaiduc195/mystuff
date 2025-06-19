#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void display(bool **a)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j])
                cout << "X ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isUpper(char a)
{
    return a <= 'Z' && a >= 'A';
}

void readFile(bool **&a)
{
    fstream input("input.txt", ios::in);
    if (!input.is_open())
    {
        cout << "Can not open file input." << endl;
        return;
    }

    a = new bool *[4];
    for (int i = 0; i < 4; i++)
        a[i] = new bool[4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = false;
        }
    }

    bool x[4][4] = {{1, 1, 0, 0},
                    {1, 1, 0, 0},
                    {1, 1, 0, 0},
                    {1, 1, 0, 0}};

    bool y[4][4] = {{0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0}};

    bool z[4][4] = {{1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};

    bool t[4][4] = {{0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};

    char buffer[1000];

    while (input.getline(buffer, 1000))
    {
        // bool X = false,Y = false,Z = false,T = false;
        bool newA[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                newA[i][j] = 1;
            }
        }

        for (size_t v = 0; v < strlen(buffer); v++)
        {
            if (buffer[v] == 'x' || buffer[v] == 'X')
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        newA[i][j] = (isUpper(buffer[v])) ? (newA[i][j] and !x[i][j]):(newA[i][j] and x[i][j]);
                    }
                }
            }
            else if (buffer[v] == 'Y' || buffer[v] == 'y')
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        newA[i][j] = (isUpper(buffer[v])) ? (newA[i][j] and !y[i][j]):(newA[i][j] and y[i][j]);
                    }
                }
            }
            else if (buffer[v] == 'z' || buffer[v] == 'Z')
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        newA[i][j] = (isUpper(buffer[v])) ? (newA[i][j] and !z[i][j]):(newA[i][j] and z[i][j]);
                    }
                }
            }
            else if (buffer[v] == 't' || buffer[v] == 'T')
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        newA[i][j] = (isUpper(buffer[v])) ? (newA[i][j] and !t[i][j]):(newA[i][j] and t[i][j]);
                    }
                }
            }
        }

        // Update a
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a[i][j] = a[i][j] or newA[i][j];
            }
        }
    }

    input.close();
}

int main()
{
    bool **kar;
    readFile(kar);
    display(kar);
    return 0;
}
