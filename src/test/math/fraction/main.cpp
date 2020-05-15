#include <iostream>

#include "../../../include/raffer/math/fraction/fraction.hpp"



namespace raffer // interface
{

[[nodiscard]] constexpr int gcd(int a, int b);

} // namespace raffer

namespace raffer // implementation
{

constexpr int gcd(int a, int b)
{ return b == 0 ? a : gcd(b, a % b); }

} // namespace raffer









auto main() -> int // test
{
    auto f = raffer::fraction<raffer::fraction<int>, raffer::fraction<int>>{{5, 7}, {5, 7}};

    std::cout << "+" << f << " = " << +f << std::endl;
    std::cout << "-" << f << " = " << -f << std::endl;
    std::cout << f << " + " << f << " = " << f + f << std::endl;
    std::cout << f << " - " << f << " = " << f - f << std::endl;
    std::cout << f << " * " << f << " = " << f * f << std::endl;
    std::cout << f << " / " << f << " = " << f / f << std::endl;
    std::cout << f << " == " << f << " = " << (f == f) << std::endl;
    std::cout << f << " != " << f << " = " << (f != f) << std::endl;
    std::cout << f << " < " << f << " = " << (f < f) << std::endl;
    std::cout << f << " > " << f << " = " << (f > f) << std::endl;
    std::cout << f << " <= " << f << " = " << (f <= f) << std::endl;
    std::cout << f << " >= " << f << " = " << (f >= f) << std::endl;

    std::cout << "double(" << f << ") = " << static_cast<double>(f) << std::endl;

    int i, j;
    ((i)) = 5;

    auto fi = raffer::fraction<int, int>{};
    fi = 7;
    fi += raffer::fraction<int, int>(6);
    --fi;
    std::cout << (--fi)++;

    constexpr raffer::fraction<int, int> f2(4, 3);
    constexpr double d = double(f2);
    std::cout << d << std::endl;

    raffer::fraction<int, int> f3 = {4, 3};
    //static_cast<double>(f3);

    auto const c1 = cmp(1.333, f3);
    auto const c2 = cmp(f3, f3);
    auto const c3 = cmp(f3, 1.333);
    std::cout << c1 << c2 << c3;
    std::cout << (1.3333333333 == f3);
}
