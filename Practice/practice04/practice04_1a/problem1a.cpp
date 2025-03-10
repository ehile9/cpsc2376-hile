#include <iostream>
#include <iomanip>

// Function to convert temperature
double convertTemperature(double temp, char scale = 'F')
{
    if (scale == 'F')
    {
        return (temp * 9.0 / 5.0) + 32.0; // Celsius to Fahrenheit
    }
    else if (scale == 'C')
    {
        return (temp - 32.0) * 5.0 / 9.0; // Fahrenheit to Celsius
    }
    return temp;
}

int main()
{
    int choice;
    double temp, convertedTemp;
    char scale;

    do
    {
        std::cout << "1. Convert Celsius to Fahrenheit\n";
        std::cout << "2. Convert Fahrenheit to Celsius\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice != 1 && choice != 2)
        {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        std::cout << "Enter temperature: ";
        std::cin >> temp;

        if (choice == 1)
        {
            convertedTemp = convertTemperature(temp, 'F');
            std::cout << "Converted: " << std::fixed << std::setprecision(2) << convertedTemp << "F\n";
        }
        else
        {
            convertedTemp = convertTemperature(temp, 'C');
            std::cout << "Converted: " << std::fixed << std::setprecision(2) << convertedTemp << "C\n";
        }

        std::cout << "Do you want to convert another temperature? (y/n): ";
        char again;
        std::cin >> again;

        if (again != 'y' && again != 'Y')
        {
            break;
        }

    } while (true);

    std::cout << "Goodbye!\n";
    return 0;
}