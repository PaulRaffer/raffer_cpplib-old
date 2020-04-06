#include <ratio>
#include <iostream>
#include <chrono>
#include <type_traits>

template <typename Rep, typename Period = std::ratio<1>>
class length;







/*template<typename To, typename Rep, typename Period>
constexpr To length_cast(length<Rep, Period> const & l)
{
	typedef std::ratio_divide<Period, typename To::period> cf;
	typedef std::common_type_t<typename To::rep, Rep, intmax_t> cr;

    return To(static_cast<typename To::rep>(static_cast<cr>(l.count()) * static_cast<cr>(cf::num) / static_cast<cr>(cf::den)));
}*/

template<typename To, typename From>
constexpr To unit_cast(From const & l)
{
	typedef std::ratio_divide<typename From::period, typename To::period> cf;
	typedef std::common_type_t<typename To::rep, typename From::rep, intmax_t> cr;

    return To(
        static_cast<typename To::rep>(static_cast<cr>(l.count())
        * static_cast<cr>(cf::num)
        / static_cast<cr>(cf::den)));
}

template <typename Rep, typename Period>
class length
{
public:
    using rep = Rep;
    using period = Period;

    constexpr length() = default;
	length(length const &) = default;

    template<typename Rep2>
    constexpr explicit length(Rep2 const & r)
    : r{static_cast<rep>(r)} {}

    template<typename Rep2, typename Period2>
    constexpr length(length<Rep2, Period2> const & l)
    : r(unit_cast<length>(l).count()) {}

    [[nodiscard]] constexpr auto count() const { return r; }

    [[nodiscard]] static constexpr length zero() noexcept { return length(rep(0)); }
    [[nodiscard]] static constexpr length min() noexcept { return length(std::numeric_limits<rep>::lowest()); }
    [[nodiscard]] static constexpr length max() noexcept { return length(std::numeric_limits<rep>::max()); }



private:
    rep r;
};



#if 0
template <typename N> using basic_yoctometers = length<N, std::yocto>;
template <typename N> using basic_zeptometers = length<N, std::zepto>;
#endif
template <typename N> using basic_attometers = length<N, std::atto>;
template <typename N> using basic_femtometers = length<N, std::femto>;
template <typename N> using basic_picometers = length<N, std::pico>;
template <typename N> using basic_nanometers = length<N, std::nano>;
template <typename N> using basic_micrometers = length<N, std::micro>;
template <typename N> using basic_millimeters = length<N, std::milli>;
template <typename N> using basic_centimeters = length<N, std::centi>;
template <typename N> using basic_decimeters = length<N, std::deci>;
template <typename N> using basic_meters = length<N>;
template <typename N> using basic_decameters = length<N, std::deca>;
template <typename N> using basic_hectometers = length<N, std::hecto>;
template <typename N> using basic_kilometers = length<N, std::kilo>;
template <typename N> using basic_megameters = length<N, std::mega>;
template <typename N> using basic_gigameters = length<N, std::giga>;
template <typename N> using basic_terameters = length<N, std::tera>;
template <typename N> using basic_petameters = length<N, std::peta>;
template <typename N> using basic_exameters = length<N, std::exa>;
#if 0
template <typename N> using basic_zettameters = length<N, std::zetta>;
template <typename N> using basic_yottameters = length<N, std::yotta>;
#endif

template <typename N> using basic_yards = length<N, std::ratio<1'143, 1'250>>;
template <typename N> using basic_inches = length<N, std::ratio<127, 5'000>>;
template <typename N> using basic_angstroems = length<N, std::ratio<1, 10'000'000'000>>;








#if 0
using yoctometers = basic_yoctometers<int64_t>;
using zeptometers = basic_zeptometers<int64_t>;
#endif
using attometers = basic_attometers<int64_t>;
using femtometers = basic_femtometers<int64_t>;
using picometers = basic_picometers<int64_t>;
using nanometers = basic_nanometers<int64_t>;
using micrometers = basic_micrometers<int64_t>;
using millimeters = basic_millimeters<int64_t>;
using centimeters = basic_centimeters<int64_t>;
using decimeters = basic_decimeters<int64_t>;
using meters = basic_meters<int64_t>;
using decameters = basic_decameters<int64_t>;
using hectometers = basic_hectometers<int64_t>;
using kilometers = basic_kilometers<int64_t>;
using megameters = basic_megameters<int64_t>;
using gigameters = basic_gigameters<int64_t>;
using terameters = basic_terameters<int64_t>;
using petameters = basic_petameters<int64_t>;
using exameters = basic_exameters<int64_t>;
#if 0
using zettameters = basic_zettameters<int64_t>;
using yottameters = basic_yottameters<int64_t>;
#endif



#if 0
constexpr auto operator""_ym(unsigned long long ym) -> yoctometers { return yoctometers{ym}; }
constexpr auto operator""_ym(long double ym) -> basic_yoctometers<long double> { return basic_yoctometers<long double>{ym}; }
constexpr auto operator""_zm(unsigned long long zm) -> zeptometers { return zeptometers{zm}; }
constexpr auto operator""_zm(long double zm) -> basic_zeptometers<long double> { return basic_zeptometers<long double>{zm}; }
#endif
constexpr auto operator""_am(unsigned long long am) -> attometers { return attometers{am}; }
constexpr auto operator""_am(long double am) -> basic_attometers<long double> { return basic_attometers<long double>{am}; }
constexpr auto operator""_fm(unsigned long long fm) -> femtometers { return femtometers{fm}; }
constexpr auto operator""_fm(long double fm) -> basic_femtometers<long double> { return basic_femtometers<long double>{fm}; }
constexpr auto operator""_pm(unsigned long long pm) -> picometers { return picometers{pm}; }
constexpr auto operator""_pm(long double pm) -> basic_picometers<long double> { return basic_picometers<long double>{pm}; }
constexpr auto operator""_nm(unsigned long long nm) -> nanometers { return nanometers{nm}; }
constexpr auto operator""_nm(long double nm) -> basic_nanometers<long double> { return basic_nanometers<long double>{nm}; }
constexpr auto operator""_um(unsigned long long um) -> micrometers { return micrometers{um}; }
constexpr auto operator""_um(long double um) -> basic_micrometers<long double> { return basic_micrometers<long double>{um}; }
constexpr auto operator""_mm(unsigned long long mm) -> millimeters { return millimeters{mm}; }
constexpr auto operator""_mm(long double mm) -> basic_millimeters<long double> { return basic_millimeters<long double>{mm}; }
constexpr auto operator""_cm(unsigned long long cm) -> centimeters { return centimeters{cm}; }
constexpr auto operator""_cm(long double cm) -> basic_centimeters<long double> { return basic_centimeters<long double>{cm}; }
constexpr auto operator""_dm(unsigned long long dm) -> decimeters { return decimeters{dm}; }
constexpr auto operator""_dm(long double dm) -> basic_decimeters<long double> { return basic_decimeters<long double>{dm}; }
constexpr auto operator""_m(unsigned long long m) -> meters { return meters{m}; }
constexpr auto operator""_m(long double m) -> basic_meters<long double> { return basic_meters<long double>{m}; }
constexpr auto operator""_dam(unsigned long long dam) -> decameters { return decameters{dam}; }
constexpr auto operator""_dam(long double dam) -> basic_decameters<long double> { return basic_decameters<long double>{dam}; }
constexpr auto operator""_hm(unsigned long long hm) -> hectometers { return hectometers{hm}; }
constexpr auto operator""_hm(long double hm) -> basic_hectometers<long double> { return basic_hectometers<long double>{hm}; }
constexpr auto operator""_km(unsigned long long km) -> kilometers { return kilometers{km}; }
constexpr auto operator""_km(long double km) -> basic_kilometers<long double> { return basic_kilometers<long double>{km}; }
constexpr auto operator""_Mm(unsigned long long Mm) -> megameters { return megameters{Mm}; }
constexpr auto operator""_Mm(long double Mm) -> basic_megameters<long double> { return basic_megameters<long double>{Mm}; }
constexpr auto operator""_Gm(unsigned long long Gm) -> gigameters { return gigameters{Gm}; }
constexpr auto operator""_Gm(long double Gm) -> basic_gigameters<long double> { return basic_gigameters<long double>{Gm}; }
constexpr auto operator""_Tm(unsigned long long Tm) -> terameters { return terameters{Tm}; }
constexpr auto operator""_Tm(long double Tm) -> basic_terameters<long double> { return basic_terameters<long double>{Tm}; }
constexpr auto operator""_Pm(unsigned long long Pm) -> petameters { return petameters{Pm}; }
constexpr auto operator""_Pm(long double Pm) -> basic_petameters<long double> { return basic_petameters<long double>{Pm}; }
constexpr auto operator""_Em(unsigned long long Em) -> exameters { return exameters{Em}; }
constexpr auto operator""_Em(long double Em) -> basic_exameters<long double> { return basic_exameters<long double>{Em}; }
#if 0
constexpr auto operator""_Zm(unsigned long long Zm) -> zettameters { return zettameters{Zm}; }
constexpr auto operator""_Zm(long double Zm) -> basic_zettameters<long double> { return basic_zettameters<long double>{Zm}; }
constexpr auto operator""_Ym(unsigned long long Ym) -> yottameters { return yottameters{Ym}; }
constexpr auto operator""_Ym(long double Ym) -> basic_yottameters<long double> { return basic_yottameters<long double>{Ym}; }
#endif









template <
    typename T,
    typename = void>
struct is_quantity
: std::false_type {};


template <
    typename T>
struct is_quantity<
    T,
    std::void_t<
        typename T::rep,
        typename T::period,
        decltype (std::declval<T>().count())>>
: std::true_type {};


template <
    typename T>
constexpr auto is_quantity_v = is_quantity<T>::value;










int main()
{
    /*std::chrono::hours h(1); // one hour
    std::chrono::milliseconds ms{3.8}; // 3 milliseconds
    std::chrono::duration<int, std::kilo> ks(3); // 3000 seconds

    // error: treat_as_floating_point<int>::value == false,
    // This duration allows whole tick counts only
//  std::chrono::duration<int, std::kilo> d3(3.5);

    // 30Hz clock using fractional ticks
    std::chrono::duration<double, std::ratio<1, 30>> hz30(3.5);

    // 3000 microseconds constructed from 3 milliseconds
    std::chrono::microseconds us = ms;
    // error: 1/1000000 is not divisible by 1/1000
//  std::chrono::milliseconds ms2 = us
    std::chrono::duration<double, std::milli> ms2 = us + ms; // 3.0 milliseconds
    std::cout << ms2.count();*/

    std::cout << is_quantity_v<attometers> << std::endl;

    std::chrono::hours h(1); // one hour
    millimeters mm{3.7}; // 3 milliseconds
    mm.count();
    std::chrono::duration<int, std::kilo> ks(3); // 3000 seconds

    // error: treat_as_floating_point<int>::value == false,
    // This duration allows whole tick counts only
//  std::chrono::duration<int, std::kilo> d3(3.5);

    // 30Hz clock using fractional ticks
    std::chrono::duration<double, std::ratio<1, 30>> hz30(3.5);
    //std::cout << meters::min().count();
    // 3000 microseconds constructed from 3 milliseconds
    micrometers um = mm;
    //mm = um;
    //um = mm;
    // error: 1/1000000 is not divisible by 1/1000
//  std::chrono::milliseconds ms2 = us
    length<double, std::milli> mm2 = um; // 3.0 milliseconds
    std::cout << um.count() << std::endl;

    basic_meters<double> m{1};
    basic_yards<double> y{m};

    std::cout << y.count() << std::endl;
}
