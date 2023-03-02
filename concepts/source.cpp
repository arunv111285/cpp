// Concept: Set of constraints on template parameters that are evaluated at compile time.
//          Can be used in Class/function templates to control function overloads and class specializations

// Usage
// template <typename T>
// requires CONDITION
// void doSomething(T param)
//          OR
// template <typename T>
// void doSomething(T param) requires CONDITION

#include <vector>
#include <numeric>
#include <iostream>

template <typename T>
double average(const std::vector<T> & v) requires std::integral<T>
{
    const double sum = std::accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

int main()
{
    // Case 1
    std::vector<int> v = {1,2,3,4,5};
    std::cout << average(v) << std::endl;

    // Case 2
    std::vector<std::string> s = {"abc", "pqr"};
    std::cout << average(s) << std::endl;
}

//
// Why? Cleaner errors.
// Error without concepts for Case 2
/*
In file included from source.cpp:13:
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/numeric:171:38: error: invalid operands to binary expression ('typename remove_reference<double &>::type' (aka 'double') and 'const std::string')
        __init = _VSTD::move(__init) + *__first;
                 ~~~~~~~~~~~~~~~~~~~ ^ ~~~~~~~~
source.cpp:19:29: note: in instantiation of function template specialization 'std::accumulate<std::__wrap_iter<const std::string *>, double>' requested here
    const double sum = std::accumulate(v.begin(), v.end(), 0.0);
                            ^
source.cpp:29:18: note: in instantiation of function template specialization 'average<std::string>' requested here
    std::cout << average(s) << std::endl;
                 ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4294:1: note: candidate template ignored: deduced conflicting types for parameter '_CharT' ('double' vs. 'char')
operator+(_CharT __lhs, const basic_string<_CharT,_Traits,_Allocator>& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4364:1: note: candidate template ignored: deduced conflicting types for parameter '_CharT' ('double' vs. 'char')
operator+(_CharT __lhs, basic_string<_CharT,_Traits,_Allocator>&& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/__iterator/move_iterator.h:172:1: note: candidate template ignored: could not match 'move_iterator' against 'basic_string'
operator+(typename move_iterator<_Iter>::difference_type __n, const move_iterator<_Iter>& __x)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/__iterator/reverse_iterator.h:221:1: note: candidate template ignored: could not match 'reverse_iterator' against 'basic_string'
operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& __x)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/__iterator/wrap_iter.h:278:21: note: candidate template ignored: could not match '__wrap_iter' against 'basic_string'
__wrap_iter<_Iter1> operator+(typename __wrap_iter<_Iter1>::difference_type __n, __wrap_iter<_Iter1> __x) _NOEXCEPT
                    ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4269:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4282:1: note: candidate template ignored: could not match 'const _CharT *' against 'typename remove_reference<double &>::type' (aka 'double')
operator+(const _CharT* __lhs , const basic_string<_CharT,_Traits,_Allocator>& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4306:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs, const _CharT* __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4318:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs, _CharT __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4332:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(basic_string<_CharT, _Traits, _Allocator>&& __lhs, const basic_string<_CharT, _Traits, _Allocator>& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4340:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs, basic_string<_CharT, _Traits, _Allocator>&& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4348:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(basic_string<_CharT, _Traits, _Allocator>&& __lhs, basic_string<_CharT, _Traits, _Allocator>&& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4356:1: note: candidate template ignored: could not match 'const _CharT *' against 'typename remove_reference<double &>::type' (aka 'double')
operator+(const _CharT* __lhs , basic_string<_CharT,_Traits,_Allocator>&& __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4373:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(basic_string<_CharT, _Traits, _Allocator>&& __lhs, const _CharT* __rhs)
^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string:4381:1: note: candidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'double'
operator+(basic_string<_CharT, _Traits, _Allocator>&& __lhs, _CharT __rhs)
^
1 error generated.
*/

// Error with concepts
/*
source.cpp:31:18: error: no matching function for call to 'average'
    std::cout << average(s) << std::endl;
                 ^~~~~~~
source.cpp:17:8: note: candidate template ignored: constraints not satisfied [with T = std::string]
double average(const std::vector<T> & v) requires std::integral<T>
       ^
source.cpp:17:56: note: because 'std::string' does not satisfy 'integral'
double average(const std::vector<T> & v) requires std::integral<T>
                                                       ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/concepts:198:20: note: because 'is_integral_v<std::string>' evaluated to false
concept integral = is_integral_v<_Tp>;
                   ^
1 error generated.
*/