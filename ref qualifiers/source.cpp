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

int main()
{
    Foo f;
    f.doSomething();
    f.doSomethingLVal();

    Foo{}.doSomething();
    
    Foo{}.doSomethingLVal();    // Error: 'this' argument to member function 'doSomethingLVal' is an rvalue, but function has non-const lvalue ref-qualifier

    f.doSomethingRVal();        // Error: 'this' argument to member function 'doSomethingRVal' is an lvalue, but function has rvalue ref-qualifier
}