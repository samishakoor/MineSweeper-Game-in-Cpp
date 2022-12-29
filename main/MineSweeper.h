#pragma once
class MineSweeper : public Game
{

public:
//Parameterized Constructor
    MineSweeper(int r, int c);
//Print Function which was declared Pure Virtual in Parent Game Class
    void PrintShowTable();
//Place Mines Randomly in the Hidden Main Table
    void PlaceMines();
//Function to Play the Game
    void PlayGame();
//Destructor
    ~MineSweeper();

};
