#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

// Function template for calculation
template <typename T>
T calculate(T a, T b, char op) 
{
    switch (op) 
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b != 0) return a / b;
        std::cerr << "Error: Division by zero is not allowed.\n";
        return 0;
    default:
        std::cerr << "Error: Invalid operator.\n";
        return 0;
    }
}

// Function to determine if the input contains a decimal point
bool isDoubleInput(const std::string& input) 
{
    return input.find('.') != std::string::npos;
}

// Function to read user input and determine type
void runCalculator() 
{
    std::string input1, input2;
    char op;

    // Get first number
    std::cout << "Enter first number: ";
    std::cin >> input1;

    // Get operation
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    // Get second number
    std::cout << "Enter second number: ";
    std::cin >> input2;

    // Determine type based on input format
    if (isDoubleInput(input1) || isDoubleInput(input2)) 
    {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        double result = calculate(num1, num2, op);
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << "\n";
    }
    else 
    {
        int num1 = std::stoi(input1);
        int num2 = std::stoi(input2);
        int result = calculate(num1, num2, op);
        std::cout << "Result: " << result << "\n";
    }
}

int main() 
{
    std::cout << " This is a simple calculator program that allows addition, subtraction, multiplication or division \n ";

    char choice;
    do 
    {
        runCalculator();
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Goodbye!\n";
    return 0;
}
// Used AI for Template function 