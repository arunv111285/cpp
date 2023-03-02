
#include <concepts>

template <typename T>
concept Composable = requires(T a, T b) { a + b; }; // requires(T a, T b) { return a + b;}; is a "requires expression"

template <typename T>
    requires Composable<T> // Requires clause
auto add(T a, T b)
{
    return a + b;
}

// Alternatively we could combine the requires expression and clause together like below
template <typename T>
    requires requires (T a, T b) { a + b; }
T add2(T a, T b)
{
    return a + b;
}

template <typename T>
  requires requires (T& x, T& y) { x.swap(y); }
void swap(T& x, T& y) 
{
  return x.swap(y);
}

//-----------------------------
// Requires Expression
//-----------------------------
// Kinds of requires expression
template <typename T>
concept Fooable = requires(T a)
{
    // 1. Simple requirements
    ++a;    // Can be pre incremented.
    a++;    // Can be post incremented.

    // 2. type requirements
    typename T::value_type;     // Has an inner type member value_type

    // 3. Compound requirements
    {a + 1} -> std::convertible_to<T>;  // a + 1 is a valid expression AND
                                        // its result must be convertible to a T

    // 4. Nested requirements
    requires std::same_as<T*, decltype(&a)>; // operator& returns the same type as T*
};

// Propeties
// - Is a compile time expression of type bool and can appear anywhere a compile time boolean can appear(for e.g. static_assert, if constexpr etc.)
// - These are not limited to body of concepts or in requires clauses.
// - Expressions inside requires expression are never evaluated. 
// - Its a template and only evaluated when the template is instantiated. 
// - Can evaluate to true or false.
// - If the body of a requires expression is empty, it evaluates to true.

//-----------------------------
// Requires Clauses
//-----------------------------
// - Is a way to specify a constraint on a template argument or function declaration.
// - requires keyword must be followed by a constant/requires expression. The latter results in 'requires requires' syntax.

template <typename T>
T increment(T val) requires std::integral<T>
{
    return val + 1;
}

// Above can also be rewritten as
template <typename T>
    requires std::integral<T>
T increment2(T val)
{
    return val + 1;
}

// Another form where we want to allow increment for all cases where val + 1 is possible
template <typename T>
    //requires requires (T x) { x + 1;}
T increment3(T val) requires requires (T x) { x + 1;} // also works
{
    return val + 1;
}



int main()
{
    int x = add(3, 2);
    //auto y = add("blah", "swah");
    //auto z = add2("mwah", "mwah");
    auto inc = increment(3);
    //auto inc2 = increment("blah");
}


