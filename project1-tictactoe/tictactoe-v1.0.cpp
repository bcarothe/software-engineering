/**
 Kent State University
 CS 33901 Software Engineering
 Fall 2017
 Project #1
 Simple Tic Tac Toe
 tictactoe-v0.9.cpp
 Source: http://paste4btc.com/enVArEWu
 Author #1: NVitanovic, https://www.youtube.com/user/NVitanovic
 */

#include "board.hpp"
#include "player.hpp"
using namespace std;

char currentPlayer = 'X';
void togglePlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {
    board board;
    player player_X;
    player player_O;
    
    // "random" seed
    std::srand((unsigned int)time(NULL));
    
    char opponent;
    cout << "Play against a [p]layer or [b]ot? ";
    cin >> opponent;
    while (opponent != 'p' && opponent != 'b') {
        if (opponent == 'q')
            return 0;
        cout << "Please press 'p' for player or 'b' for bot. Press 'q' for quit: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opponent;
    }
    
    
    string quit;
    char cashout;
    
    while (quit != "quit") {
        if (quit == "restart") {
            quit = "";
            for (int i = 0; i < 3; ++i)
                board.scoreboard[i] = 0;
            player_X.consecutive_wins = 0;
            player_O.consecutive_wins = 0;
        }
        
        board.emptyBoard();
        board.drawBoard();
        
        while (board.checkBoardForWinOrTie() != 'T' && quit != "restart") {
            int a;
            //Input
            if (currentPlayer == 'X' || (currentPlayer == 'O' && opponent != 'b')) {
                cout << "Press the number of the field: ";
                cin >> a;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (currentPlayer == 'O' && opponent == 'b')
                a = rand()%9 + 1;
            else
                a = NULL;
            
            if (a == 1 && board.matrix[0][0] != 'X' && board.matrix[0][0] != 'O')
                board.matrix[0][0] = currentPlayer;
            else if (a == 2 && board.matrix[0][1] != 'X' && board.matrix[0][1] != 'O')
                board.matrix[0][1] = currentPlayer;
            else if (a == 3 && board.matrix[0][2] != 'X' && board.matrix[0][2] != 'O')
                board.matrix[0][2] = currentPlayer;
            else if (a == 4 && board.matrix[1][0] != 'X' && board.matrix[1][0] != 'O')
                board.matrix[1][0] = currentPlayer;
            else if (a == 5 && board.matrix[1][1] != 'X' && board.matrix[1][1] != 'O')
                board.matrix[1][1] = currentPlayer;
            else if (a == 6 && board.matrix[1][2] != 'X' && board.matrix[1][2] != 'O')
                board.matrix[1][2] = currentPlayer;
            else if (a == 7 && board.matrix[2][0] != 'X' && board.matrix[2][0] != 'O')
                board.matrix[2][0] = currentPlayer;
            else if (a == 8 && board.matrix[2][1] != 'X' && board.matrix[2][1] != 'O')
                board.matrix[2][1] = currentPlayer;
            else if (a == 9 && board.matrix[2][2] != 'X' && board.matrix[2][2] != 'O')
                board.matrix[2][2] = currentPlayer;
            else {
                cout << "\nYou must enter a number from 1 to 9 AND it must not have been selected before!\n";
                continue;
            }
            togglePlayer();
            board.drawBoard();
            
            // When X wins
            if (board.checkBoardForWinOrTie() == 'X') {
                ++board.scoreboard[0];
                cout << "X wins!\nScore: X: " << board.scoreboard[0] << " Ties: " << board.scoreboard[1] << " O: " << board.scoreboard[2] << "\n";
                
                player_O.consecutive_wins = 0;
                ++player_X.consecutive_wins;
                
                if (player_X.consecutive_wins == 3) {
                    cout << "Would you like to cash out for $300K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #300K!\n";
                        return 0;
                    }
                }
                else if (player_X.consecutive_wins == 6) {
                    cout << "Would you like to cash out for $600K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #600K!\n";
                        return 0;
                    }
                }
                else if (player_X.consecutive_wins == 9) {
                    cout << "Would you like to cash out for $900K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #900K!\n";
                        return 0;
                    }
                }
                else if (player_X.consecutive_wins == 10) {
                    cout << "Congratulations for winning #1M!\n";
                    return 0;
                }
                
                cout << "Consecutive wins: " << player_X.consecutive_wins;
                cout << "\nType \"quit\" to quit, \"restart\" for a fresh start, or anything else to continue. ";
                cin >> quit;
                togglePlayer();
                break;
            }
            
            // When O wins
            else if (board.checkBoardForWinOrTie() == 'O') {
                ++board.scoreboard[2];
                cout << "O wins!\nScore: X: " << board.scoreboard[0] << " Ties: " << board.scoreboard[1] << " O: " << board.scoreboard[2] << "\n";
                
                player_X.consecutive_wins = 0;
                ++player_O.consecutive_wins;
                
                if (player_O.consecutive_wins == 3) {
                    cout << "Would you like to cash out for $300K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #300K!\n";
                        return 0;
                    }
                }
                else if (player_O.consecutive_wins == 6) {
                    cout << "Would you like to cash out for $600K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #600K!\n";
                        return 0;
                    }
                }
                else if (player_O.consecutive_wins == 9) {
                    cout << "Would you like to cash out for $900K? (y/n): ";
                    cin >> cashout;
                    if (cashout == 'y') {
                        cout << "Congratulations for winning #900K!\n";
                        return 0;
                    }
                }
                else if (player_O.consecutive_wins == 10) {
                    cout << "Congratulations for winning #1M!\n";
                    return 0;
                }
                
                cout << "Consecutive wins: " << player_O.consecutive_wins;
                cout << "\n\nType \"quit\" to quit, \"restart\" for a fresh start, or anything else to continue. ";
                cin >> quit;
                break;
            }
            // When tie
            else if (board.checkBoardForWinOrTie() == 'T') {
                ++board.scoreboard[1];
                cout << "Tie game!\nScore: X: " << board.scoreboard[0] << " Ties: " << board.scoreboard[1] << " O: " << board.scoreboard[2] << "\n";
                cout << "\nType \"quit\" to quit, \"restart\" for a fresh start, or anything else to continue. ";
                cin >> quit;
                player_X.consecutive_wins = 0;
                player_O.consecutive_wins = 0;
                break;
            }
            
        }
        
    }
    
    
    
    return 0;
}

