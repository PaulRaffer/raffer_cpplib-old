#include "../../lib/point/point.hpp"

#include <iostream>

auto main() -> int
{
    /*raffer::point_2d<int> p;
    p.set_y(9);
    std::cout << p.get_y();*/

    raffer::point_2d<int> p2{4, 9};
    //p2.set_z(9);
    std::cout << p2.get_y();
    std::cout << raffer::point_3d<int>::dimensions;

}
