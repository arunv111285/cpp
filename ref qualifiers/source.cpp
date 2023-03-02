#include <iostream>

class Foo
{
public:
    Foo() = default;
    ~Foo() = default;
    void doSomething() const{
        std::cout << __FUNCTION__ << std::endl;
    }

    void doSomethingLVal() &{
        std::cout << __FUNCTION__ << std::endl;
    }

    void doSomethingRVal() &&{
        std::cout << __FUNCTION__ << std::endl;
    }
};

/*int main()
{
    Foo f;
    f.doSomething();
    f.doSomethingLVal();

    Foo{}.doSomething();

    Foo{}.doSomethingLVal();    // Error: 'this' argument to member function 'doSomethingLVal' is an rvalue, but function has non-const lvalue ref-qualifier

    f.doSomethingRVal();        // Error: 'this' argument to member function 'doSomethingRVal' is an lvalue, but function has rvalue ref-qualifier
}*/


// Additional considerations
#include <vector>

class Keeper
{
    std::vector<int> data_{1, 2, 3, 4, 5};

public:
    Keeper() {
        std::cout << __FUNCTION__ << std::endl;
    }

    ~Keeper() {
        std::cout << __FUNCTION__ << std::endl;
    }

    auto & items()
    {
        return data_;
    } 

    auto & itemsLVal() &
    {
        return data_;
    }

    auto itemsRVal() && 
    {
        return std::move(data_); // Move it since the object the method is getting called is a temporary that is going to die soon
    }
};

int main()
{
    for (auto & val : Keeper{}.items()) // Lifetime of items not extended as Keeper is a temporary that dies off.
    {
        std::cout << val << " ";
    }

    /*for (auto & val : Keeper{}.itemsLVal()) // Error: 'this' argument to member function 'itemsLVal' is an rvalue, but function has non-const lvalue ref-qualifier
    {
        std::cout << val << " ";
    }*/

    for (auto & val : Keeper{}.itemsRVal())
    {
        std::cout << val << " ";
    }
}