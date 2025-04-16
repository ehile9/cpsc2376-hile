#include "connect_four.h"

// Constructor: Initializes Board
Game::Game() : board(ROWS* COLS, EMPTY), currentPlayer(PLAYER_1) {}

// Function to drop a piece into a column
bool Game::dropPiece(int col) 
{
    for (int row = ROWS - 1; row >= 0; --row) 
    {
        int index = row * COLS + col;
        if (board[index] == EMPTY) 
        {
            board[index] = currentPlayer;
            return true;
        }
    }
    return false; //column is full
}

// Function to check if the board is full (for draw condition)
bool Game::isBoardFull() const 
{
    for (int c = 0; c < COLS; ++c) 
    {
        if (board[c] == EMPTY) 
        {
            return false;
        }
    }
    return true;
}

// Function to check if the current player has won
bool Game::checkWin(Token player) const 
{
    // Horizontal Check
    for (int r = 0; r < ROWS; ++r) 
    {
        for (int c = 0; c <= COLS - 4; ++c) 
        {
            if (board[r * COLS + c] == player && board[r * COLS + c + 1] == player &&
                board[r * COLS + c + 2] == player && board[r * COLS + c + 3] == player) 
            {
                return true;
            }
        }
    }
    // Vertical Check
    for (int c = 0; c < COLS; ++c) 
    {
        for (int r = 0; r <= ROWS - 4; ++r) 
        {
            if (board[r * COLS + c] == player && board[(r + 1) * COLS + c] == player &&
                board[(r + 2) * COLS + c] == player && board[(r + 3) * COLS + c] == player) 
            {
                return true;
            }
        }
    }
    // Diagonal (Bottom-left to Top-right)
    for (int r = 3; r < ROWS; ++r) 
    {
        for (int c = 0; c <= COLS - 4; ++c) 
        {
            if (board[r * COLS + c] == player && board[(r - 1) * COLS + (c + 1)] == player &&
                board[(r - 2) * COLS + (c + 2)] == player && board[(r - 3) * COLS + (c + 3)] == player) 
            {
                return true;
            }
        }
    }
    // Diagonal (Top-left to Bottom-right)
    for (int r = 0; r <= ROWS - 4; ++r) 
    {
        for (int c = 0; c <= COLS - 4; ++c) {
            if (board[r * COLS + c] == player && board[(r + 1) * COLS + (c + 1)] == player &&
                board[(r + 2) * COLS + (c + 2)] == player && board[(r + 3) * COLS + (c + 3)] == player) 
            {
                return true;
            }
        }
    }

    return false;
}

// Play Function: Executes a move
bool Game::play(int column) 
{
    if (column < 0 || column >= COLS) 
    {
        std::cout << "Invalid move! Column is out of range.  Choose between 1 and 7. \n";
        return false;  // Invalid move.
    }

    if (!dropPiece(column))
    {
        std::cout << "Column is full! Choose another column. \n";
        return false;  // Message column is full
    }
    // Check if the game ended
    if (checkWin(currentPlayer)) 
    {
        return true;
    }
    if (isBoardFull()) 
    {
        return true;
    }
    // Swap Player
    currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;

    return true;
}

// Get Game Status
GameState Game::status() const 
{
    if (checkWin(PLAYER_1)) return PLAYER_1_WINS;
    if (checkWin(PLAYER_2)) return PLAYER_2_WINS;
    if (isBoardFull()) return DRAW;
    return ONGOING;
}

// Overloaded << Operator to Print Board
std::ostream& operator<<(std::ostream& os, const Game& game) 
{
    os << "\n 1 2 3 4 5 6 7\n";
    for (int r = 0; r < ROWS; ++r) 
    {
        os << "|";
        for (int c = 0; c < COLS; ++c) 
        {
            os << static_cast<char>(game.board[r * COLS + c]) << "|";
        }
        os << "\n";
    }
    os << "---------------\n";
    return os;
}
