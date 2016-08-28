#include <cassert>

class Plus {
    int value;

public:
    Plus(int v)
        : value(v)
    {
    }

    template <typename T>
    auto operator()(T x) const
    {
        return x + value;
    }
};

int main(void)
{
    auto plus = Plus(1);
    assert(plus(42) == 43);
}
