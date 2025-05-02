#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> nums;

    std::cout << "Enter the number of elements: ";
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

    // Calculate sum of elements
    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    // Calculate product of elements
    int product = std::accumulate(
        nums.begin(), nums.end(), 1,
        [](int acc, int val) { return acc * val; }
    );

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Product: " << product << "\n";

    return 0;
}
