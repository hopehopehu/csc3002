#include<iostream>
#include<grid.h>
#include<vector.h>
#include"console.h"
using namespace std;

void display_board(Grid<char> & board);
void set_board(Grid<char> & board, Vector<char> & elements);
void set_elements(Grid<char> & board, Vector<char> & elements);
bool checkWinningLine(Grid<char> & board, char mark, int row, int col,
                      int dRow, int dCol);
int checkForWin(Grid<char> & board, char mark);
void testWin(Grid<char> & board);
void get_user_move(Grid<char> & board, Vector <char> & elements);
void get_com_move(Grid<char> & board, Vector <char> & elements);
int score(Grid<char> & board);
int maxsearch(Grid<char> & board, Vector <char> & elements);
int minsearch(Grid<char> & board, Vector <char> & elements);


Vector <char> elements(9);

Grid<char> board = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
struct Move{
    int row;
    int col;
};
Move minimax(Grid<char> & board, Vector <char> & elements);

void display_board(Grid<char> & board){
    cout << "-------"<<endl;
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            if (column != 2){
                cout << "|" << board[row][column];
            }
            else{
                cout << "|" << board[row][column] << "|" << endl;
            }
        }
        cout << "-------"<<endl;
    }
}
void set_board(Grid<char> & board, Vector<char> & elements){
    int index = 0;
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            board[row][column] = elements[index];
            index++;
        }
    }
}
void set_elements(Grid<char> & board, Vector<char> & elements){
    int index = 0;
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            elements[index] = board[row][column];
            index++;
        }
    }
}

void get_user_move(Grid<char> & board, Vector <char> & elements){
    cout << "pls input the position of your move (1-9)"<<endl;
    int move;
    cin  >> move;
    set_elements(board, elements);
    if(move >= 1 && move <= 9 && elements[move - 1] == ' '){
        move--;
        elements[move] = 'O';
        set_board(board, elements);
    }
}

bool checkWinningLine(Grid<char> & board, char mark, int row, int col,
                      int dRow, int dCol) {
    for (int i = 0; i < 3; i++) {
        if (board[row][col] != mark) return false;
        row += dRow;
        col += dCol;
    }
    return true;
}

int checkForWin(Grid<char> & board, char mark) {
    for (int i = 0; i < 3; i++) {
        if (checkWinningLine(board, mark, i, 0, 0, 1)) return 1;
        if (checkWinningLine(board, mark, 0, i, 1, 0)) return 1;
    }
    if (checkWinningLine(board, mark, 0, 0, 1, 1)) return 1;
    if (checkWinningLine(board, mark, 2, 0, -1, 1)) return 1;
    return 0;
}

void testWin(Grid<char> & board) {
    if (checkForWin(board, 'X') == 1) cout << "X has won" << endl;
    if (checkForWin(board, 'O') == 1) cout << "O has won" << endl;
    cout << endl;
}

int score(Grid<char> & board){
    if (checkForWin(board, 'X') == 1) return -10;
    if (checkForWin(board, 'O') == 1) return 10;
    return 0;
}

bool gameover(Grid<char> & board, Vector <char> & elements){
    if (checkForWin(board, 'X') == 1 || checkForWin(board, 'O') == 1) {
        return true;
    }// someone win
    bool fullity = true;
    for (int index = 0; index < 9; index++){
        if (elements[index] == ' '){
            fullity = false;
        }
    }
    return fullity;//draw game
}

Move minimax(Grid<char> & board, Vector <char> & elements){
    int best_move_score = 100;
    Move best_move;
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (board[row][col] == ' '){
                board[row][col] = 'X'; // try of move
                int temp_move_score = maxsearch(board, elements);
                if(temp_move_score <= best_move_score){
                    best_move_score = temp_move_score;
                    best_move.row = row;
                    best_move.col = col;
                }
                board[row][col] = ' ';
            }
        }
    }
    return best_move;
}
int maxsearch(Grid<char> & board, Vector <char> & elements){
    if (gameover(board, elements)) return score(board);
    Move best_move;
    int best_move_score = -1000;
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (board[row][col] == ' '){
                board[row][col] = 'O';
                int temp_move_score = minsearch(board, elements);
                if(temp_move_score >= best_move_score){
                    best_move_score = temp_move_score;
                    best_move.row = row;
                    best_move.col = col;
                }
                board[row][col] = ' ';
            }
        }
    }
    return best_move_score;
}

int minsearch(Grid<char> & board, Vector <char> & elements){
    if (gameover(board, elements)) return score(board);
    Move best_move;
    int best_move_score = 1000;
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (board[row][col] == ' '){
                board[row][col] = 'X';
                int temp_move_score = maxsearch(board, elements);
                if(temp_move_score <= best_move_score){
                    best_move_score = temp_move_score;
                    best_move.row = row;
                    best_move.col = col;
                }
                board[row][col] = ' ';
            }
        }
    }
    return best_move_score;

}

void play(){
    int turn = 0;
    set_elements(board, elements);
    cout <<"this is the game board"<<endl;
    cout <<"(0,0) position can be filled by 1, (0,1) is 2,....(2,2) is 9"<<endl;
    display_board(board);
    while(!gameover(board, elements)){
        if (turn % 2 == 1){//'O' 's turn
            get_user_move(board, elements);
            testWin(board);
            turn++;
            display_board(board);
        }
        else{
            cout << endl << "computer move: " << endl;
            Move aimove = minimax(board, elements);
            board[aimove.row][aimove.col] = 'X';
            testWin(board);
            turn++;
            display_board(board);
        }
    }
    cout<<"this is the end of game, thanks!"<<endl;
}

int P2TicTacToe(){
    play();
    cout<<"this is the end of game, thanks!"<<endl;
    return 0;
}
