#include <iostream>
#include <vector>

const int ROWS = 6;  
const int COLS = 7;  

// Function to create the board
std::vector<std::vector<char>> createBoard() 
{
    return std::vector<std::vector<char>>(ROWS, std::vector<char>(COLS, '-'));
}

// Function to print the board
void printBoard(const std::vector<std::vector<char>>& board) 
{
    std::cout << "\n 1 2 3 4 5 6 7" << std::endl; // Column numbers
    for (const auto& row : board) 
    {
        std::cout << "|";
        for (char cell : row) 
        {
            std::cout << cell << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl; // Bottom border
}

int main() 
{
    std::vector<std::vector<char>> board = createBoard(); // Initialize board
    printBoard(board); 

    return 0;
}
