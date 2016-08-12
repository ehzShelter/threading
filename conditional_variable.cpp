#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

// global variable
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void printId(int id)
{
    std::unique_lock<std::mutex> lck(mtx);

    while (!ready) {
        cv.wait(lck);
    }

    std::cout << "thread " << id << std::endl;
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;

    cv.notify_all();
}

int main(void)
{
    std::thread myThread[10];

    // spawn 10 threads
    for (int i = 0; i < 10; i++)
    {
        myThread[i] = std::thread(printId, i);
    }

    std::cout << "10 threads ready to go .. I mean race...\n";

    go();

    for (auto& th : myThread)
    {
        th.join();
    }
}
