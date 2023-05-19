#include <iostream>

/*struct Point
{
    double x, y;
};

int main()
{
    Point pt{3,5};
    auto [x,y] = pt;
    // What happens behind the scenes for the above line
    /*
    auto __tmp = pt;
    auto &x = get<0>(__tmp);
    auto &y = get<1>(__tmp);
    // Note the reference above
    */
    //std::cout << "x = " << x << ", y = " << y << std::endl;
//}

class Point;
template <> struct std::tuple_size<Point> : std::integral_constant<size_t, 2>{};
template <> struct std::tuple_element<0, Point> { using type = double; };
template <> struct std::tuple_element<1, Point> { using type = double; };

class Point
{
    public:
        Point(double x, double y) : x_(x), y_(y){}
        constexpr double getX() const noexcept { return x_; }
        constexpr double getY() const noexcept { return y_; }
        constexpr void setX(double x) noexcept { x_ = x; }
        constexpr void setY(double y) noexcept { y_ = y; }

        template <size_t N>
        constexpr decltype(auto) get() const noexcept
        {
            if constexpr(N == 1) 
            {
                return x_;
            }
            else if constexpr(N == 0)
            {
                return y_;
            }
        }

    private:
        double x_,y_;
};

int main()
{
    Point pt(3,5);
    auto [x,y] = pt;
}
