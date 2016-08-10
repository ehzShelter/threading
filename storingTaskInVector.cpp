#include <future>
#include <iostream>
#include <thread>
#include <vector>

int twice(int m)
{
    return 2 * m;
}

void HelloThread()
{
    std::cout << "Hello World ...!" << std::endl;
}

int main(void)
{
    // vector will store future data type it is  returning int
    std::vector<std::future<int>> futureTasks;
    std::vector<std::future<void>> voidTasking;

    for (int i = 0; i < 10; i++) {
        futureTasks.push_back(std::async(twice, i));
    }

    for (int i = 0; i < 10; ++i) {
        futureTasks.push_back(std::async([](int m) { return 2 * m; }, i));
    }

    for (int i = 0; i < 10; i++) {
        voidTasking.push_back(std::async(HelloThread));
    }

    for (int i = 0; i < 10; i++) {
        voidTasking.push_back(std::async([]() {
            std::cout << "hello I am captured in Lambda...";
        }));
    }

    for (auto& voidTask : voidTasking) {
        voidTask.get();
    }

    for (auto& e : futureTasks) {
        std::cout << e.get() << std::endl;
    }
}
