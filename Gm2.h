#include <iostream>
#include <string>
using namespace std ;
#ifndef CS213_A3_OBJECTORIENTEDPROGRAMMING_GM2_H
#define CS213_A3_OBJECTORIENTEDPROGRAMMING_GM2_H

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
public:// Return true  if move is valid and put it on board within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x, int y, char symbol) = 0;
    // Returns true if there is any winner either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner(char symbol ) = 0; // Return true if all moves are done and no winner
    virtual bool is_draw() = 0; // Display the board and the pieces on it
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;// Return true if game is over
};
// This class represents a player who has a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    virtual void get_move_2(int& x, int& y);

    string to_string();// Give player info as a string
    char get_symbol() const;// Get symbol used by player
};
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);// Take a symbol and pass it to parent
    void get_move(int& x, int& y); // Generate a random move
    void get_move_2(int& x, int& y);
};
class gm_3 : public Board {
public:
    gm_3 ();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner(char symbol );
    bool is_draw();
    bool game_is_over();
};
class gm_3_mng {
private:
    Board* boardPtr;
    Player* players[2];
public:
    gm_3_mng( Board* , Player* playerPtr[2]);
    void run_gm3();
};


class my_triangle  : public Board{
public:
    my_triangle();
    bool update_board(int x, int y, char symbol) ;
    bool is_winner(char symbol);
    void display_board() ;
    bool is_draw() ;
    bool game_is_over() ;
};
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];

public:
    GameManager(Board* bPtr, Player* playerPtr[2]);
    void run();
};
class Connect4Board : public Board {
public:
    Connect4Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner(char symbol );
    bool is_draw();
    bool game_is_over();
};
class GmMngr{
private:
    Board* boardPtr;
    Player* players[2];
public:
    GmMngr ( Board* , Player* playerPtr[2]);
    void run_gm2();
};
class X_O_Board :public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner(char symbol );
    bool is_draw();
    bool game_is_over();
};


#endif //CS213_A3_OBJECTORIENTEDPROGRAMMING_GM2_H
