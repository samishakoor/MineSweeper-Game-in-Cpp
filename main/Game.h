#pragma once
class Game
{

protected:

    int rows = 5;
    int cols = 5;

    char** MainTable;
    char** ShowTable;

public:
//Parameterized Constructor
    Game(int rows, int cols);
//Creating Real board which was hidden
    void MakeMainTable();
//Creating the board which has to show on screen
    void MakeShowTable();
//Pure Virtual Function making Game class , an Abstract Class
    virtual void PrintShowTable() = 0;
//Destructor
    ~Game();

};
