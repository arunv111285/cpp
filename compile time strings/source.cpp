#include <string>
#include <string_view>

constexpr size_t length1(const char * str)
{
    size_t count = 0;
    while (*str != '\0')
    {
        ++str;
        ++count;
    }
    return count;
}

constexpr size_t length2(const char * str)
{
    return std::char_traits<char>::length(str);
}

constexpr size_t length3(std::string_view sv)
{
    return sv.size();
}

constexpr size_t find1(const char * str, char ch)
{
    size_t index = 0, loc = -1;
    while (*str != '\0')
    {
        if (*str == ch)
        {
            loc = index;
            break;
        }
        ++index;
        ++str;
    }
    return loc;
}

constexpr const char * find2(const char * str, char ch)
{
    return std::char_traits<char>::find(str, length2(str), ch);
}

constexpr std::string_view::size_type find3(std::string_view sv, char ch)
{
    return sv.find(ch);
}

int main()
{
    static_assert(length1("Hello") == 5);
    static_assert(length2("Hello") == 5);
    static_assert(length3("hello") == 5);
    static_assert(find1("hello", 'e') == 1);
    static_assert(find1("hello", 'k') == -1);
    static_assert(*(find2("hello", 'e')) == 'e');
    static_assert(find2("hello", 'k') == nullptr);
    static_assert(find3("hello", 'e') == 1);
    static_assert(find3("hello", 'k') == std::string::npos);
    static_assert(std::string_view("abc") == std::string_view("abc"));
    static_assert(std::string_view("abc") != std::string_view("pbc"));

    using namespace std::string_view_literals;
    auto literalsToCreateAStringView = "abc"sv;
    std::string_view s2 = "abc\0\0def"sv;
}