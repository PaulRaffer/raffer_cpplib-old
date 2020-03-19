#include "../../lib/point/point.hpp"

#include <iostream>

int main()
{
    point_2d<int> p;
    p.set_y(9);
    std::cout << p.get_y();

    point_3d<int> p2;
    p2.set_z(9);
    std::cout << p2[2];
}
