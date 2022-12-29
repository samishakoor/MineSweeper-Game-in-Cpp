#include"Game.h"
#include<iostream>

Game::Game(int rows, int cols)
{

    this->rows = rows;
    this->cols = cols;

    MainTable = new char* [rows];
    ShowTable = new char* [rows];

    for (int i = 0; i < rows; i++)
    {
        MainTable[i] = new char[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        ShowTable[i] = new char[cols];
    }

}


Game::~Game()
{
    if (MainTable != NULL && ShowTable != NULL)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] MainTable[i];
            delete[] ShowTable[i];
        }
        delete[] MainTable;
        delete[] ShowTable;
    }
}

void Game::MakeMainTable()
{


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            MainTable[i][j] = 'X';                // Allocating 'X' to all indexes of Main Board
        }
    }
}

void Game::MakeShowTable()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ShowTable[i][j] = 'X';                // Allocating 'X' to all indexes of Board which has to be shown on Screen
        }
    }
}
