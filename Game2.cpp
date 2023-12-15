#include <iostream>
#include <string>
using namespace std ;
#include "Gm2.h"

int main() {
    int choice,ex;
    Player* players[2];
    players[0] = new Player (1, 'X');
    cout<<"if you want game 1 enter 1\n if you want game 2 enter 2\n if you want game 3 enter 3\n";
    cin>>ex;
    if (ex == 1){
        cout << "Welcome to FCAI first  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);
        GameManager gm (new my_triangle , players);
        gm.run();
    }
    else if (ex == 2){
        cout << "Welcome to FCAI second  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 7);
        GmMngr gem  (new  Connect4Board(), players);
        gem.run_gm2();
    }
    else if (ex == 3) {
        cout << "Welcome to FCAI third  Game. :)\n";
        cout << "Press 1 if you want to play with computer:\n ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'O');
        else//Player pointer points to child
            players[1] = new RandomPlayer ('O', 5);
        gm_3_mng game_3 (new gm_3(), players);
        game_3.run_gm3();
    }
    system ("pause");
}
