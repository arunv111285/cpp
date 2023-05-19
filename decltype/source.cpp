#include <iostream>

template <typename A, typename B>
auto multiply(const A & a, const B & b)
{
    return a * b;
}

int main()
{
    std::cout << multiply(3,5) << std::endl;
    std::cout << multiply(3, 5.5) << std::endl;
}

/*
When you use decltype(auto), the compiler will deduce the type of the variable based on the initializer expression, 
including any references or cv-qualifiers. It can be useful when you want to declare a variable with the same type as an expression, 
preserving references and const/volatile qualifiers.

While decltype preserves constness and reference qualifiers, it doesn't preserve value category information, such as lvalue or rvalue. 
decltype(auto) preserves both the constness, reference qualifiers, and value category of the expression, making it more precise in capturing the complete type.
*/