#include <future>
#include <iostream>

void calledFromAsync()
{
    std::cout << "Async call" << std::endl;
}

int main(void)
{
    std::future<void> result(std::async(calledFromAsync));

    std::cout << "message form main... " << std::endl;

    result.get();

    return 0;
}
