#include <iostream>
#include <chrono>
#include <windows.h>


unsigned char field[10][10] =
                    {
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 32, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 32, 219, 219, 219, 219, 219, 219, 219},
                       {32, 32, 32, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219}
                    };

unsigned char fieldB[10][10] =
                    {
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 32, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 32, 219, 219, 219, 219, 219, 219, 219},
                       {32, 32, 32, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219},
                       {219, 219, 219, 219, 219, 219, 219, 219, 32, 219}
                    };

void checkAlive(int x, int y)
{
    unsigned char cell = field[x][y];
    int neighbours = 0;

    //counting
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (
                !(i == 0 && j == 0)
                && (x+i >= 0) //beyond field
                && (x+i <= 9)
                && (y+j >= 0)
                && (y+j <= 9)
                )
            {
                if (field[x+i][y+j] == 32)
                {
                    neighbours++;
                }
            }
        }
    }

    if (cell == 32)//if alive
    {
        if (neighbours < 2)
        {
            fieldB[x][y] = 219;//die
        }
        if (neighbours > 3)
        {
            fieldB[x][y] = 219;//die
        }
    }
    else //if dead
    {
        if (neighbours == 3)
        {
            fieldB[x][y] = 32;
        }
    }

}

void calcCells()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            checkAlive(x, y);
        }
    }

    memcpy(field, fieldB, 100);
};

void print2d()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            std::cout << field[x][y];
        }
        std::cout << std::endl;
    }
}

void showGrid()
{
    print2d();
    _sleep(1000);
    system("CLS");
    calcCells();
    showGrid();
}

int main()
{
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    showGrid();
}

