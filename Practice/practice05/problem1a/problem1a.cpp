#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;
    std::cout << "Enter the number of integers: ";
    int n;
    if (!(std::cin >> n))
    {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }

    // Print all numbers using iterators
    std::cout << "You entered: ";
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Sum of even numbers using iterator-based loop
    int sumEven = 0;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        if (*it % 2 == 0)
        {
            sumEven += *it;
        }
    }

    std::cout << "Sum of even numbers: " << sumEven << "\n";
    return 0;
}
