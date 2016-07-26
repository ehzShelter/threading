#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main(void)
{
    std::vector<int> V{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = std::accumulate(V.begin(), V.end(), 0);

    int product = std::accumulate(V.begin(), V.end(), 1, std::multiplies<int>());

    std::string stringPrint = std::accumulate(
        // lambda functor
        V.begin(), V.end(), std::string{},
        [](const std::string& a, int b) {
            return a.empty() ? std::to_string(b) : a + '-' + std::to_string(b);
        });

    std::cout << "Sum : " << sum << std::endl
              << "product : " << product << std::endl
              << "dash-operated string: " << stringPrint << std::endl;
}
