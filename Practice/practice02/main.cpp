#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>  // For std::numeric_limits

const std::string FILENAME = "account_balance.txt";

// Function to read balance from file
double readBalanceFromFile() 
{
    std::ifstream inFile(FILENAME);
    double balance = 100.0; // Default balance if file doesn't exist
    if (inFile) 
    {
        inFile >> balance;
    }
    else 
    {
        std::ofstream outFile(FILENAME);
        outFile << std::fixed << std::setprecision(2) << balance;
    }
    return balance;
}

// Function to write balance to file
void writeBalanceToFile(double balance) 
{
    std::ofstream outFile(FILENAME);
    if (outFile) 
    {
        outFile << std::fixed << std::setprecision(2) << balance;
    }
    else 
    {
        std::cerr << "Error: Unable to update account balance." << std::endl;
    }
}

// Function to check balance
void checkBalance(double balance) 
{
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

// Function to get valid user input
double getValidAmount(const std::string& prompt) 
{
    double amount;
    while (true) 
    {
        std::cout << prompt;
        std::cin >> amount;

        // Check if input is valid
        if (std::cin.fail()) 
        {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Error: Invalid input. Please enter a numeric value." << std::endl;
        }
        else if (amount <= 0) 
        {
            std::cerr << "Error: Amount must be positive." << std::endl;
        }
        else 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            return amount;
        }
    }
}

// Function to deposit money
double deposit(double balance) 
{
    double amount = getValidAmount("Enter deposit amount: ");
    balance += amount;
    writeBalanceToFile(balance);
    std::cout << "Deposit successful. Your new balance is: $" << balance << std::endl;
    return balance;
}

// Function to withdraw money
double withdraw(double balance) 
{
    while (true) 
    {
        double amount = getValidAmount("Enter withdrawal amount: ");
        if (amount > balance) 
        {
            std::cerr << "Error: Insufficient funds. Your balance is $" << balance << std::endl;
        }
        else 
        {
            balance -= amount;
            writeBalanceToFile(balance);
            std::cout << "Withdrawal successful. Your new balance is: $" << balance << std::endl;
            return balance;
        }
    }
}

// Function to get valid menu choice
int getValidChoice() 
{
    int choice;
    while (true) 
    {
        std::cout << "\nMenu:\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 4) 
        {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Error: Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
        else 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            return choice;
        }
    }
}

int main() 
{
    double balance = readBalanceFromFile();
    std::cout << "Welcome to Your Bank Account!" << std::endl;

    while (true) 
    {
        int choice = getValidChoice();
        switch (choice) 
        {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            balance = deposit(balance);
            break;
        case 3:
            balance = withdraw(balance);
            break;
        case 4:
            std::cout << "Exiting program. Have a great day!" << std::endl;
            return 0;
        }
    }
}
//Used AI to help me create input validation function and to clear the Cin errors
