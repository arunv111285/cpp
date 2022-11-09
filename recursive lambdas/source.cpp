#include <iostream>

/*
Doesn't work because fib is being used inside the fib function before it is(fib function) being defined
constexpr auto fib = [](int val)
{
    if (val <= 2)
        return 1;
    return fib(val - 1) + fib(val - 2);
};
*/

constexpr auto fib_ = [](const auto fib, int val)
{
    if (val <= 2)
        return 1;
    return fib(fib, val - 1) + fib(fib, val - 2);
};

constexpr auto fib = [](int val)
{
    return fib_(fib_, val);
};


int main()
{
    std::cout << "5th fibonacci number is : " << fib(5) << std::endl;
}