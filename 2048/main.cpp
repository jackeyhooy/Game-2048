#include <iostream>
#include <iomanip>
#include "game2048.h"

using namespace std;

int main()
{
    cout <<"      "<<"========================================"<<endl;
    cout <<"      "<<"=                                      ="<<endl;
    cout <<"      "<<"=          Welcome to My 2048          ="<<endl;
    cout <<"      "<<"=                                      ="<<endl;
    cout <<"      "<<"========================================"<<endl;


    cout <<"      "<<"======================================="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=   12   =   64   =    64  =    12    ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"======================================="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=   32   =   16   =   128  =     8    ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"======================================="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"======================================="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"=        =        =        =          ="<<endl;
    cout <<"      "<<"======================================="<<endl;
    Game2048 game;
    game.debug();
    char input;
    while(cin >>input)
    {
        if('a' == input)
            game.moveLeft();
        else if('d' == input) {
            game.moveRight();
        }else if('w' == input)
        {
            game.moveUp();
        }else if('s' == input)
            game.moveDown();
        game.debug();
    }


    return 0;
}

