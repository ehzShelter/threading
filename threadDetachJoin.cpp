#include <iostream>
#include <thread>

void functionInChildThread()
{
    std::cout << "Beauty is only skin-deep" << std::endl;
}

int main(void)
{
    // t1 starts running
    std::thread t1(functionInChildThread);
    // t1.join() ;// main  threads waits for t1 to finish
    t1.detach(); // t1 will freely on its own -- daemon process

    // ..
    if (t1.joinable()) {
        // main thred is so fast so that t1 threads will not join
        t1.join();
    }
}
