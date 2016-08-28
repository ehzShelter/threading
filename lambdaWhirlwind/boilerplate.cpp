#include <cassert>

class Plus {
    int value;

public:
    Plus(int v)
        : value(v)
    {
    }

    int operator()(int x) const
    {
        return x + this->value;
    }
};

int main(void)
{
    auto plus = Plus(1);
    // assert(plus.operator()(42) == 43);
    assert(plus(42) == 43);
}
