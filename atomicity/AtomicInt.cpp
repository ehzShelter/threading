#include <thread>
#include <mutex>
#include <iostream>

class AtomicInt {
    public:
    int get() const {
        std::lock_guard<std::mutex> l(m);
        return value;
    }

    int set(int newValue) {
        std::lock_guard<std::mutex> l(m);
        return std::exchange(value, newValue);
    }

    private:
    mutable std::mutex m;
    int value;
};

int main(void)
{
    AtomicInt atomicity;
    std::cout << atomicity.get() << std::endl;
    atomicity.set(-1);
    std::cout << atomicity.get() << std::endl;
}

