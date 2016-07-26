#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void makeBreak(int milisec)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
}

int temperature(void)
{
    std::cout << "Husband: Oh no, we don't a newspaper " << std::endl;

    std::cout << "Husband: I will look it up on the internet!" << std::endl;
    std::cout << "Husband: Here it is, "
              << "It says tomorrow will be 40 .." << std::endl;

    return 40;
}

int main(void)
{
    std::cout << "Wife: ..Tomorrow, we are going on a picnic.\n"
              << "Wife: What will be the weather, I mean temperature" << std::endl;

    std::future<int> answer = std::async(std::launch::deferred, temperature);

    std::cout << "Wife:    I should pack for tomorrow." << std::endl;

    std::cout << "Wife:    Hopefully my husband can figure out the weather soon."
              << std::endl;

    int temp = answer.get();

    std::cout << "Wife:    Finally, tomorrow will be " << temp << "... Em...\n"
              << "         \"In which units is the answer?\""
              << std::endl;
}
