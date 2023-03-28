#include <type_traits>

class Empty
{

};

class A
{
    Empty e;
    int i;
};

class B
{
    [[no_unique_address]] Empty e;
    int i;
};

class C
{
    char c;
    [[no_unique_address]] Empty e1, e2;
};

class D
{
    char c[2];
    [[no_unique_address]] Empty e1, e2;
};

int main()
{
    static_assert(sizeof(Empty) == 1);
    static_assert(sizeof(A) == 2 * sizeof(int));
    static_assert(sizeof(B) == sizeof(int));
    static_assert(sizeof(C) == 2);
    static_assert(sizeof(D) == 3);
}