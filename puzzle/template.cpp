#include <cstdio>

template <typename T>
auto kitten(T t)
{
    static T x;
    return (x += 1) + t;
}

int main(void)
{
    printf("%d\n ", kitten(1));
    printf("%g\n ", kitten(3.14));
}
