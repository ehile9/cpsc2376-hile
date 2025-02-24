#include <iostream>
#include <vector>
#include <limits>

const int ROWS = 6;
const int COLS = 7;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Token { EMPTY = '-', PLAYER_1 = 'X', PLAYER_2 = 'O' };

// Function to display game rules
void displayRules()
{
    std::cout << "=======================================\n";
    std::cout << "        WELCOME TO CONNECT FOUR\n";
    std::cout << "=======================================\n";
    std::cout << "How to Play:\n";
    std::cout << "1. Players take turns dropping tokens into a column (1-7).\n";
    std::cout << "2. The token falls to the lowest available space in that column.\n";
    std::cout << "3. The first player to connect four in a row (vertically, horizontally, or diagonally) wins.\n";
    std::cout << "4. If the board fills up and no one wins, the game is a draw.\n";
    std::cout << "=======================================\n";
}

// Function to create a 1D board
std::vector<Token> createBoard()
{
    return std::vector<Token>(ROWS * COLS, Token::EMPTY);
}

// Function to print the board
void printBoard(const std::vector<Token>& board)
{
    std::cout << "\n 1 2 3 4 5 6 7" << std::endl;
    for (int r = 0; r < ROWS; ++r)
    {
        std::cout << "|";
        for (int c = 0; c < COLS; ++c)
        {
            std::cout << static_cast<char>(board[r * COLS + c]) << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl;
}

// Function to get user input (validated)
int getUserColumn()
{
    int col;
    while (true)
    {
        std::cout << "Enter column (1-7): ";
        if (std::cin >> col && col >= 1 && col <= 7)
        {
            return col - 1;  // Convert to 0-based index
        }
        else
        {
            std::cout << "Invalid input! Enter a number between 1 and 7.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Function to drop a piece into a column
bool dropPiece(std::vector<Token>& board, int col, Token player)
{
    for (int row = ROWS - 1; row >= 0; row--)
    {
        int index = row * COLS + col;
        if (board[index] == Token::EMPTY)
        {
            board[index] = player;
            return true;
        }
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(const std::vector<Token>& board)
{
    for (int c = 0; c < COLS; c++)
    {
        if (board[c] == Token::EMPTY)
        {
            return false;
        }
    }
    return true;
}

// Function to check for a win
bool checkWin(const std::vector<Token>& board, Token player)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            if (board[r * COLS + c] == player && board[r * COLS + c + 1] == player &&
                board[r * COLS + c + 2] == player && board[r * COLS + c + 3] == player)
            {
                return true;
            }
        }
    }
    for (int c = 0; c < COLS; c++)
    {
        for (int r = 0; r <= ROWS - 4; r++)
        {
            if (board[r * COLS + c] == player && board[(r + 1) * COLS + c] == player &&
                board[(r + 2) * COLS + c] == player && board[(r + 3) * COLS + c] == player)
            {
                return true;
            }
        }
    }
    return false;
}

// Function to determine game status
GameState gameStatus(const std::vector<Token>& board)
{
    if (checkWin(board, Token::PLAYER_1)) return GameState::PLAYER_1_WINS;
    if (checkWin(board, Token::PLAYER_2)) return GameState::PLAYER_2_WINS;
    if (isBoardFull(board)) return GameState::DRAW;
    return GameState::ONGOING;
}

// Function to play the game
void play()
{
    std::vector<Token> board = createBoard();
    Token players[] = { Token::PLAYER_1, Token::PLAYER_2 };
    int turn = 0;
    GameState state = GameState::ONGOING;

    while (state == GameState::ONGOING)
    {
        printBoard(board);
        Token currentPlayer = players[turn % 2];
        std::cout << "Player " << (turn % 2) + 1 << " (" << static_cast<char>(currentPlayer) << ") ";

        int col;
        while (true)
        {
            col = getUserColumn();
            if (dropPiece(board, col, currentPlayer))
            {
                break;
            }
            else
            {
                std::cout << "Column full! Choose another.\n";
            }
        }

        state = gameStatus(board);
        turn++;
    }

    printBoard(board);
    if (state == GameState::PLAYER_1_WINS)
    {
        std::cout << "Player 1 (X) wins!\n";
    }
    else if (state == GameState::PLAYER_2_WINS)
    {
        std::cout << "Player 2 (O) wins!\n";
    }
    else
    {
        std::cout << "It's a Draw!\n";
    }
}

// Main function: Runs the game
//int main()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    displayRules();

    while (true)
    {
        play();

        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (choice != 'y' && choice != 'Y')
        {
            std::cout << "Thanks for playing!\n";
            break;
        }
    }

    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}