// File name:CS213_A3_OBJECTORIENTEDPROGRAMMING_GM2_H
// Purpose:three games type tic tac toe
// Author(s): Menna Ali Abd elbaky , Donia Kareem Muhammed
// ID(s): 20221168 , 20221051
// Section:s3
// Date:22/12/2023
// Version:v3
#include <iostream>
#include <string>
#include "Gm2.h"
using namespace std ;
int main() {
    string choice,ex;
    Player* players[2];
    players[0] = new Player (1, 'X');
    cout<<"If You Want Pyramid Tic-Tac-Toe Game enter 1\n If You Want Four-in-a-row Game enter 2\n "
          "If You Want 5 x 5 Tic Tac Toe Game  enter 3\n"" If You Want e X-O Game  enter 4\n" ;
    cin>>ex;
    if (ex == "1"){
        cout << "Welcome to FCA first  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != "1")
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);
        GameManager gm (new my_triangle , players);
        gm.run();
    }
    else if (ex == "2"){
        cout << "Welcome to FCA second  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != "1")
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 7);
        GmMngr gem  (new  Connect4Board(), players);
        gem.run_gm2();
    }
    else if (ex == "3") {
        cout << "Welcome to FCA third  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != "1")
            players[1] = new Player (2, 'O');
        else//Player pointer points to child
            players[1] = new RandomPlayer ('O', 5);
        gm_3_mng game_3 (new gm_3(), players);
        game_3.run_gm3();
    }
    else if (ex == "4"){
        cout << "Welcome to FCA third  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != "1")
            players[1] = new Player (2, 'O');
        else//Player pointer points to child
            players[1] = new RandomPlayer ('O', 3);
       GameManager X_O (new X_O_Board(), players);
        X_O.run();
    }
    else
        cout<<"YOU OPTION FALSE \n";

    system ("pause");
}
