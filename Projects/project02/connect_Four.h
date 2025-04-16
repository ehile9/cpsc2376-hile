#pragma once
#ifndef connect_Four_H
#define connect_Four_H

#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

// Enumerations for Game State and Tokens
enum GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum Token { EMPTY = '-', PLAYER_1 = 'X', PLAYER_2 = 'O' };

class Game 
{
private:
    std::vector<Token> board;
    Token currentPlayer;

    // Private Helper Functions
    bool dropPiece(int col);
    bool checkWin(Token player) const;
    bool isBoardFull() const;

public:
    Game();
    bool play(int column);
    GameState status() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif
