#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

/*_____________________________________________________*/
// #define int (unsigned int)
int row = 0, col = 0;
vector<vector<double>> matrix;
/*_____________________________________________________*/

// MANIPULATION
void Swap(int rA, int rB)
{

    if (rA < 1 || rB < 1 || rA > row || rB > row || rA == rB) return;
    swap(matrix[rA - 1], matrix[rB - 1]);
}

void subtract(int rA, int rB, int k)
{
    if (rA > row || rB > row)
        return;

    for (int i = 0; i < col; i++)
    {
        matrix[rA - 1][i] -= k * matrix[rB - 1][i];
    }
}

void add(int rA, int rB, int k)
{
    subtract(rA, rB, -k);
}

void getOne(int rA)
{
    if (rA > row)
        return;
    double divisor = 1;
    for (int i = 0; i < col; i++)
    {
        if (matrix[rA - 1][i])
        {
            divisor = matrix[rA - 1][i];
            break;
        }
    }
    if (divisor == 1.0)
        return;
    for (int i = 0; i < col; i++)
    {
        if (matrix[rA - 1][i])
            matrix[rA - 1][i] /= divisor;
    }
}

void display()
{
    if (matrix.size() == 0)
    {
        cout << "BLANK" << endl;
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}
void input()
{
    do
    {
        cin >> row >> col;
    } while (row <= 0 || col <= 0);

    matrix.resize(row);
    for (int i = 0; i < row; i++)
    {
        matrix[i].resize(col);
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void eliminate(int u, int v)
{
    if (u > col || u < 1)
        return;
    if (v < 1 || v > row)
        return;
    getOne(v);
    for (int i = 0; i < row; i++)
    {
        if (i != v - 1)
        {
            subtract(i + 1, v, matrix[i][u - 1]);
        }
    }
}

void ManualDriver()
{
    string command = "";

    while (command != "exit")
    {
        cout<<">>>> ";
        cin >> command;
        if (command == "swap")
        {
            int x, y;
            do
            {
                cin >> x >> y;
            } while (x <= 0 || y <= 0);

            Swap(x, y);
            display();
        }
        else if (command == "sub")
        {
            int x, y;
            int k;
            do
            {
                cin >> x;
            } while (x <= 0);
            cin >> k;
            do
            {
                cin >> y;
            } while (y <= 0);
            subtract(x, y, k);
            display();
        }
        else if (command == "add")
        {
            int x, y;
            int k;
            do
            {
                cin >> x;
            } while (x <= 0);
            cin >> k;
            do
            {
                cin >> y;
            } while (y <= 0);
            add(x, y, k);
            display();
        }
        else if (command == "one")
        {
            int a;
            do
            {
                cin >> a;
            } while (a <= 0);

            getOne(a);
            display();
        }
        else if (command == "new")
        {
            cout << "INPUT NEW MATRIX" << endl;
            input();
            cout << "CURRENT MATRIX" << endl;
            display();
        }
        else if (command == "elim")
        {
            int x, y;
            do
            {
                cin >> x >> y;
            } while (x < 0 || y < 0);
            eliminate(x, y);
            display();
        }
    }
}

void autoDriver()
{
    string command = "";

    while (command != "exit")
    {
        if (command == "new")
        {
            cout << "Input matrix: ";
            input();
            display();
            int r = 0, c = 0;
            int step = 1;
            while (r < row && c < col)
            {
                // Find fundamental element
                while (r < row && !matrix[r][c])
                    r++;

                // manipulate on col
                if (r == row)
                {
                    r = step-1;
                    c++;
                    continue;
                }
                else
                {
                    Swap(r + 1, step);
                    r = step - 1;
                    getOne(step);
                    // Eliminate
                    eliminate(c + 1, step);
                    r++;
                    c++;
                }
                step++;
            }
            cout<<endl;
            cout<<"ANSWER "<<endl;
            display();
        }
        cout<<">>>> ";
        cin >> command;
    }
}

int main()
{
    // cin >> row >> col;
    // cout << ">>>> ";

    // driver();
    string command = "";
    while (command != "exit")
    {
        cout<<">>>>";
        cin >> command;
        if (command == "manual")
        {
            ManualDriver();
        }
        else if (command == "auto")
        {
            autoDriver();
        }
    }

    return 0;
}