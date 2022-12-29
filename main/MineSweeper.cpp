#include"Game.h"
#include"MineSweeper.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

MineSweeper::MineSweeper(int r, int c) :Game(r, c)
{

}

void MineSweeper::PrintShowTable()
{
    cout << "BOARD : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << ShowTable[i][j];
        }
        cout << endl;
    }

}

void MineSweeper::PlaceMines()
{

    int no_of_mines = 5;
    srand(time(NULL));
    for (int i = 0; i < no_of_mines; i++)
    {

        int a, b;
        while (true)
        {
            a = rand() % (rows - 1);                         //Randomly Allocate Mines to the Main Board(Hidden)
            b = rand() % (cols - 1);
            if (a == 0 && b == 0)
            {
                i--;
                break;
            }
            if (MainTable[a][b] != 'M')
            {
                MainTable[a][b] = 'M';
                break;
            }
        }
    }

}

void MineSweeper::PlayGame()
{


    int x;
    int y;
    bool isMine = false;
    bool c = false;
    cout << "The Game Should Always Start From  0,0 Coordinates" << endl;

    while (!isMine)
    {
        int count = 0;               // Count Number of mines in main hidden Board
        int win = 0;
        cout << "Enter Coordinates (x,y) : ";
        cin >> x;
        cin >> y;
        if (!c)
        {
            if (x == 0 && y == 0)
                c = true;
            else {
                system("CLS");

                cout << "Please Enter Appropriate Coordinates ! " << endl << endl;
            }
        }

        if (c)
        {
            cout << endl;
            if (x >= 0 && y >= 0 && x < rows && y < cols)
            {
                if (MainTable[x][y] != 'M')
                {
                    if (x != 0)
                    {
                        if (MainTable[x - 1][y] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x < 4)
                    {
                        if (MainTable[x + 1][y] == 'M')
                        {
                            count++;
                        }
                    }
                    if (y < 4)
                    {
                        if (MainTable[x][y + 1] == 'M')
                        {
                            count++;
                        }

                    }
                    if (y != 0)
                    {
                        if (MainTable[x][y - 1] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x != 0 && y < 4)
                    {
                        if (MainTable[x - 1][y + 1] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x != 0 && y != 0)
                    {
                        if (MainTable[x - 1][y - 1] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x < 4 && y < 4)
                    {
                        if (MainTable[x + 1][y + 1] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x < 4 && y != 0)
                    {
                        if (MainTable[x + 1][y - 1] == 'M')
                        {
                            count++;
                        }
                    }
                    if (x == 0 && y == 0)
                    {

                        for (int i = 0; i < 2; i++)
                            for (int j = 0; j < cols; j++)
                            {
                                int count = 0;
                                if (i != 0)
                                {
                                    if (MainTable[i - 1][j] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (i < 2)
                                {
                                    if (MainTable[i + 1][j] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (j < 4)
                                {
                                    if (MainTable[i][j + 1] == 'M')
                                    {
                                        count++;
                                    }

                                }
                                if (j != 0)
                                {
                                    if (MainTable[i][j - 1] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (i != 0 && j < 4)
                                {
                                    if (MainTable[i - 1][j + 1] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (i != 0 && j != 0)
                                {
                                    if (MainTable[i - 1][j - 1] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (i < 4 && j < 4)
                                {
                                    if (MainTable[i + 1][j + 1] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (i < 4 && j != 0)
                                {
                                    if (MainTable[i + 1][j - 1] == 'M')
                                    {
                                        count++;
                                    }
                                }
                                if (MainTable[i][j] == 'M')
                                    ShowTable[i][j] = 'X';
                                else
                                    ShowTable[i][j] = count + '0';
                            }
                        for (int i = 2; i < 5; i++)
                            for (int j = 0; j < 5; j++)
                            {
                                ShowTable[i][j] = 'X';
                            }
                        system("CLS");
                        PrintShowTable();
                    }

                    else
                    {
                        ShowTable[x][y] = count + '0';
                        system("CLS");
                        PrintShowTable();
                    }

                }

                if (MainTable[x][y] == 'M')
                {
                    ShowTable[x][y] = 'M';
                    system("CLS");
                    PrintShowTable();
                    cout << "Sorry ! You Lost The Game , A mine has exploded at location (" << x << "," << y << ")" << endl;
                    isMine = true;
                }
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                    {
                        if (ShowTable[i][j] == 'X')
                            win++;

                    }
                if (win == 5)
                {
                    cout << endl;
                    cout << "Congratulations! You have Won the Game";
                    break;
                }
            }


            else
            {
                cout << "Please Enter Appropriate Coordinates ! " << endl << endl;
            }
        }


    }
}
MineSweeper::~MineSweeper()
{

}
