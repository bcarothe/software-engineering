#ifndef board_hpp
#define board_hpp

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;







class board {
public:
    char matrix[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int scoreboard[3] = {0, 0, 0};
    void drawBoard();
    void emptyBoard();
    char checkBoardForWinOrTie();
};






#endif /* board_hpp */
