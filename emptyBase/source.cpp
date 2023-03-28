#include <type_traits>

class Base
{

};

class Derived1 : Base
{
    int x;
};

class Derived2 : Base
{
    int x;
    Base b;
};

class Derived3 : Base
{
    int x;
    Derived1 d;
};

int main()
{
    static_assert(sizeof(Base) == 1);
    static_assert(sizeof(Derived1) == sizeof(int));
    static_assert(sizeof(Derived2) == 2 * sizeof(int));
    static_assert(sizeof(Derived3) == 2 * sizeof(int));
}