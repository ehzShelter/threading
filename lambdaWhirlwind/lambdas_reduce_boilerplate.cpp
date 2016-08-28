#include <cassert>

auto plus = [value = 1](int x) { return x + value; };

int main(void)
{
    assert(plus(42) == 44);
}
