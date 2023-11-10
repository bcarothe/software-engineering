#include "board.hpp"


void board::drawBoard() {
    cout << string( 100, '\n' );
    cout << "tictactoe v1.0" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void board::emptyBoard() {
    char squareNumber = '0';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ++squareNumber;
        }
    }
}

char board::checkBoardForWinOrTie() {
    // First player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    
    // Second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    
    // Checks for filled board
    else {
        bool isFilled = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] >= '1' && matrix[i][j] <= '9') {
                    isFilled = false;
                    return '/';
                }
                else
                    isFilled = true;
            }
        }
        if (isFilled) {
            return 'T';
        }
    }
    
    return '/';
}
