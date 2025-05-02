#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::cout << "Enter the number of integers: ";
    int n;
    if (!(std::cin >> n) || n <= 0)
    {
        std::cerr << "Invalid number of elements.\n";
        return 1;
    }

    std::vector<int> nums;
    nums.reserve(n);

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }

    // Print each element squared
    std::cout << "Squares:";
    std::for_each(nums.begin(), nums.end(), [](auto val)
        {
            std::cout << " " << (val * val);
        });
    std::cout << "\n";

    // Sum of squared values using transform_reduce
    auto sumSquares = std::transform_reduce(
        nums.begin(), nums.end(),
        0,
        std::plus<>(),
        [](auto v)
        {
            return v * v;
        }
    );

    std::cout << "Sum of squares: " << sumSquares << "\n";
    return 0;
}
