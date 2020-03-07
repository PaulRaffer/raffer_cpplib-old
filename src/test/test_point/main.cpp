#include "../../lib/experimental/point/point.hpp"

int main()
{
    constexpr raffer::Point<double, 1> p(5);

    constexpr raffer::Point<double, 1> q = p.get_x();

    raffer::Point_2D<double> u{};

    std::cout << p.get_x() << q.get_x() << u.get_x() << u.get_y();

    //p.set_x(7);
}
