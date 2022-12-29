#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include"Game.h"
#include"MineSweeper.h"
using namespace std;
int main()
{

    int rows = 5;
    int cols = 5;

    MineSweeper m(rows, cols);
    m.MakeMainTable();                                       //Calling Member Functions Of Base Class through object of Derived class (INHERITANCE)
    m.MakeShowTable();

    Game* g = &m;                                            //Pointer of Base Class storing the address of Derived Class(POLYMORPHISM)
    g->PrintShowTable();

    MineSweeper* M = dynamic_cast<MineSweeper*>(g);          //Down Casting of base class pointer to call non virtual functions of Derived Class

    if (M != NULL)
    {
        M->PlaceMines();
        M->PlayGame();
    }

    return 0;
}

