#include <iostream>

auto makeKitten(int capturedBYValue)
{
    static int staticOutsideLambda = 0;
    return [=](int lambdaOwnArg) {
        static int staticInsideLambda = 0;
        return (staticOutsideLambda++) + (staticInsideLambda++) + capturedBYValue + lambdaOwnArg;
    };
}

int main(void)
{
    auto kit1 = makeKitten(1);
    auto kit2 = makeKitten(2);

    std::cout << kit1(20) << " " << kit1(30) << std::endl;
    std::cout << kit2(20) << " " << kit2(30) << std::endl;
}
