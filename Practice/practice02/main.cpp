#include <iostream>
#include <fstream>
#include <iomanip>

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

// Function to deposit money
double deposit(double balance) 
{
    double amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;
    if (amount <= 0) 
    {
        std::cerr << "Error: Deposit amount must be positive." << std::endl;
        return balance;
    }
    balance += amount;
    writeBalanceToFile(balance);
    std::cout << "Deposit successful. Your new balance is: $" << balance << std::endl;
    return balance;
}

// Function to withdraw money
double withdraw(double balance) 
{
    double amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;
    if (amount <= 0) 
    {
        std::cerr << "Error: Withdrawal amount must be positive." << std::endl;
        return balance;
    }
    if (amount > balance) 
    {
        std::cerr << "Error: Insufficient funds. Your balance is $" << balance << std::endl;
        return balance;
    }
    balance -= amount;
    writeBalanceToFile(balance);
    std::cout << "Withdrawal successful. Your new balance is: $" << balance << std::endl;
    return balance;
}

int main() 
{
    double balance = readBalanceFromFile();
    int choice;
    std::cout << "Welcome to Your Bank Account!" << std::endl;

    do 
    {
        std::cout << "\nMenu:\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

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
            break;
        default:
            std::cerr << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
//Used AI to help me structure program, debug and show me how to validate user input.