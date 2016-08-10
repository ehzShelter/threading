// Futures are used with all three threads to get their results, and a promise is used with the third one to fulfill a future by means other than a return value.Also, a single thread can fulfill multiple futures with different values via promises, which it can't do otherwise.

// An easy way to think of it is that you can either set a future by returning a value
// or by using a promise.future has no set method;
// that functionality is provided by promise.You choose what you need based on what the situation allows
//

#include <future>
#include <iostream>
#include <thread>

int main(void)
{
    // future from a packaged_task
    std::packaged_task<int()> task([]() { return 7; }); // wrap the function
    std::future<int> f1 = task.get_future(); // get a future
    std::thread(std::move(task)).detach(); // launch on a thread

    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, []() { return 8; });

    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([](std::promise<int>& p) { p.set_value(9); },
        std::ref(p))
        .detach();

    std::cout << "Waiting...";
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
              << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
}
