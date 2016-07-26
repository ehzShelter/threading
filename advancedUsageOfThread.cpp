#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <thread>
#include <vector>
#include <numeric>

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
adder(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return std::accumulate(begin, end, T());
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type

parallelSum(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;

    auto midPoint = begin + std::distance(begin, end) / 2;

    std::future<T> firstProcess = std::async(std::launch::async, adder<Iterator>, begin, midPoint);
    std::future<T> secondProcess = std::async(std::launch::async, adder<Iterator>, midPoint, end);

    return firstProcess.get() + secondProcess.get();
}

int main(void)
{
    std::vector<int> v(1000000);
    for(unsigned long i = 0, n = v.size(); i < n; ++i) {
        v.push_back(i);
    }

    unsigned long total = parallelSum(v.begin(), v.end());

    std::cout << total << std::endl;
}
