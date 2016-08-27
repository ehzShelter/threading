#include <iostream>
#include <utility>
#include <atomic>
#include <ios>

struct A {
    int a[100];
};

struct B {
    int x;
    int y;
};

struct C {
    float x;
    int y;
};

int main(void)
{

    std::cout << std::boolalpha
        << "std::atomic<A> is lock free? "
        << std::atomic<A>{}.is_lock_free() << std::endl;

    std::cout << std::boolalpha
        << "std::atomic<B> is lock free? "
        << std::atomic<B>{}.is_lock_free() << std::endl;

    std::cout << std::boolalpha
        << "std::atomic<C> is lock free? "
        << std::atomic<C>{}.is_lock_free() << std::endl;
}
