#include <iostream>
#include "connect_Four.h"

int main() 
{
    Game game;
    int column;

    std::cout << "Welcome to Connect Four!\n";
    std::cout << "Players take turns dropping pieces into columns 1-7.\n";

    while (game.status() == ONGOING) 
    {
        std::cout << game;

        bool validMove = false;
        while (!validMove)  //prevents column overflow
        {
            std::cout << "Enter column (1-7): ";
            std::cin >> column;

            if (std::cin.fail() || column < 1 || column > 7)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Enter a number between 1-7.\n";
                continue;
            }

            validMove = game.play(column - 1);  // Convert to 0-based index

            /*if (!validMove)
            {
                std::cout << "Column is full! Choose another column. \n";
            }*/
        }
    }

    std::cout << game;
    GameState result = game.status();
    if (result == PLAYER_1_WINS) 
    {
        std::cout << "Player 1 (X) wins!\n";
    }
    else if (result == PLAYER_2_WINS) 
    {
        std::cout << "Player 2 (O) wins!\n";
    }
    else 
    {
        std::cout << "It's a Draw!\n";
    }

    return 0;
}
