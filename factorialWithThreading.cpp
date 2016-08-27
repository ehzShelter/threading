#include <future>
#include <iostream>

int factorial(std::future<int>& f)
{
    int temp = 1;

    int number = f.get();
    for (int i = number; i > 1; i--) {
        temp *= i;
    }

    std::cout << "Result is : " << temp << std::endl;

    return temp;
}

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));
    p.set_value(4);

    std::cout << fu.get() << std::endl;
}

void MyClass::buttonClickedEvent( int buttonId ) {
    // I need to have an access to all members of MyClass's class
}

void MyClass::setEvent() {

    void ( *func ) ( int );
    func = buttonClickedEvent; // <-- Reference to non static member function must be called

}

setEvent();


void (MyClass::*func)(int);
func = &MyClass::buttonClickedEvent;
