#include <iostream>
#include <vector>

template <typename... VALUES>
auto sumUnary(VALUES&&... values)
{
    return (values + ...);
}

template <typename... VALUES>
auto sumBinary(VALUES&&... values)
{
    return (values + ... + 0);
}

template <typename T, typename... Ts>
auto average(T value, Ts... values)
{
    return (value + ... + values) / (1.0 + sizeof...(values));
}

template <typename CONTAINER, typename... VALUES>
auto push_back(CONTAINER & c, VALUES&&... values)
{
    //(c.push_back(values), ...);
    (c.push_back(std::forward<VALUES>(values)),...);
}

int main()
{
    std::cout << sumBinary() << std::endl; 
    std::cout << sumUnary(1,2,3,4,5) << std::endl; 
    std::cout << average(1, 2, 3, 4, 5) << std::endl;
    std::vector<int> v;
    push_back(v, 1, 2, 3, 4, 5);
    for (auto val : v)
        std::cout << val << " ";
    std::cout << std::endl;
}