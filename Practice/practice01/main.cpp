//Eric Hile 
#include <iostream>
#include <vector>

// Function declarations
void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main()
{
    std::vector<int> numbers;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            std::cout << "Enter a number to add: ";
            std::cin >> num;
            numbers.push_back(num);
            break;
        }
        case 2:
            printVector(numbers);
            break;
        case 3:
            doubleVector(numbers);
            break;
        case 4:
            std::cout << "Sum of elements: " << calculateSum(numbers) << "\n";
            break;
        case 5:
        {
            int multiple;
            std::cout << "Enter a number to find multiples: ";
            std::cin >> multiple;
            printMultiples(numbers, multiple);
            break;
        }
        case 6:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

//Print vector function using const so that the function cannot change vector values
void printVector(const std::vector<int>& vec)
{
    std::cout << "Vector elements: ";
    for (const int& num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

//Double vector function
void doubleVector(std::vector<int>& vec)
{
    for (int& num : vec)
    {
        num *= 2;
    }
    std::cout << "All elements doubled!\n";
}

//Function to calculate the sum of the vector without changing the values
int calculateSum(const std::vector<int>& vec)
{
    int sum = 0;
    for (const int& num : vec)
    {
        sum += num;
    }
    return sum;
}

//Function to print multiples of the number chosen by user without changing the vector
void printMultiples(const std::vector<int>& vec, int multiple)
{
    std::cout << "Multiples of " << multiple << ": ";
    for (const int& num : vec)
    {
        if (num % multiple == 0)
        {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
}
/*Used chatgpt to help debug improper syntax and to come up with the logic for the printmultiples function*/
