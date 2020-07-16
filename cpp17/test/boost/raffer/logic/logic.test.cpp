
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201702L

#include <boost/test/unit_test.hpp>

#include <raffer/logic/logic.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_logic)

BOOST_AUTO_TEST_SUITE(logical)

BOOST_AUTO_TEST_CASE(logical_not)
{
	BOOST_TEST((raffer::logical_not(false) == true ));
	BOOST_TEST((raffer::logical_not(true ) == false));
}


BOOST_AUTO_TEST_CASE(logical_and)
{
	BOOST_TEST((raffer::logical_and(false, false, false) == false));
	BOOST_TEST((raffer::logical_and(false, false, true ) == false));
	BOOST_TEST((raffer::logical_and(false, true , false) == false));
	BOOST_TEST((raffer::logical_and(false, true , true ) == false));
	BOOST_TEST((raffer::logical_and(true , false, false) == false));
	BOOST_TEST((raffer::logical_and(true , false, true ) == false));
	BOOST_TEST((raffer::logical_and(true , true , false) == false));
	BOOST_TEST((raffer::logical_and(true , true , true ) == true ));
}


BOOST_AUTO_TEST_CASE(logical_or)
{
	BOOST_TEST((raffer::logical_or(false, false, false) == false));
	BOOST_TEST((raffer::logical_or(false, false, true ) == true ));
	BOOST_TEST((raffer::logical_or(false, true , false) == true ));
	BOOST_TEST((raffer::logical_or(false, true , true ) == true ));
	BOOST_TEST((raffer::logical_or(true , false, false) == true ));
	BOOST_TEST((raffer::logical_or(true , false, true ) == true ));
	BOOST_TEST((raffer::logical_or(true , true , false) == true ));
	BOOST_TEST((raffer::logical_or(true , true , true ) == true ));
}


BOOST_AUTO_TEST_CASE(logical_nand)
{
	BOOST_TEST((raffer::logical_nand(false, false, false) == true ));
	BOOST_TEST((raffer::logical_nand(false, false, true ) == true ));
	BOOST_TEST((raffer::logical_nand(false, true , false) == true ));
	BOOST_TEST((raffer::logical_nand(false, true , true ) == true ));
	BOOST_TEST((raffer::logical_nand(true , false, false) == true ));
	BOOST_TEST((raffer::logical_nand(true , false, true ) == true ));
	BOOST_TEST((raffer::logical_nand(true , true , false) == true ));
	BOOST_TEST((raffer::logical_nand(true , true , true ) == false));
}


BOOST_AUTO_TEST_CASE(logical_nor)
{
	BOOST_TEST((raffer::logical_nor(false, false, false) == true ));
	BOOST_TEST((raffer::logical_nor(false, false, true ) == false));
	BOOST_TEST((raffer::logical_nor(false, true , false) == false));
	BOOST_TEST((raffer::logical_nor(false, true , true ) == false));
	BOOST_TEST((raffer::logical_nor(true , false, false) == false));
	BOOST_TEST((raffer::logical_nor(true , false, true ) == false));
	BOOST_TEST((raffer::logical_nor(true , true , false) == false));
	BOOST_TEST((raffer::logical_nor(true , true , true ) == false));
}

BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(bit)

BOOST_AUTO_TEST_CASE(bit_not)
{
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b000)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b111)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b001)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b110)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b010)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b101)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b011)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b100)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b100)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b011)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b101)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b010)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b110)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b001)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_not(0b111)) == ((static_cast<unsigned int>(~0b0) << 0x3) | 0b000)));
}


BOOST_AUTO_TEST_CASE(bit_and)
{
	BOOST_TEST((raffer::bit_and(0b00, 0b00) == 0b00));
	BOOST_TEST((raffer::bit_and(0b00, 0b01) == 0b00));
	BOOST_TEST((raffer::bit_and(0b00, 0b10) == 0b00));
	BOOST_TEST((raffer::bit_and(0b00, 0b11) == 0b00));
	BOOST_TEST((raffer::bit_and(0b01, 0b00) == 0b00));
	BOOST_TEST((raffer::bit_and(0b01, 0b01) == 0b01));
	BOOST_TEST((raffer::bit_and(0b01, 0b10) == 0b00));
	BOOST_TEST((raffer::bit_and(0b01, 0b11) == 0b01));
	BOOST_TEST((raffer::bit_and(0b10, 0b00) == 0b00));
	BOOST_TEST((raffer::bit_and(0b10, 0b01) == 0b00));
	BOOST_TEST((raffer::bit_and(0b10, 0b10) == 0b10));
	BOOST_TEST((raffer::bit_and(0b10, 0b11) == 0b10));
	BOOST_TEST((raffer::bit_and(0b11, 0b00) == 0b00));
	BOOST_TEST((raffer::bit_and(0b11, 0b01) == 0b01));
	BOOST_TEST((raffer::bit_and(0b11, 0b10) == 0b10));
	BOOST_TEST((raffer::bit_and(0b11, 0b11) == 0b11));
}


BOOST_AUTO_TEST_CASE(bit_or)
{
	BOOST_TEST((raffer::bit_or(0b00, 0b00) == 0b00));
	BOOST_TEST((raffer::bit_or(0b00, 0b01) == 0b01));
	BOOST_TEST((raffer::bit_or(0b00, 0b10) == 0b10));
	BOOST_TEST((raffer::bit_or(0b00, 0b11) == 0b11));
	BOOST_TEST((raffer::bit_or(0b01, 0b00) == 0b01));
	BOOST_TEST((raffer::bit_or(0b01, 0b01) == 0b01));
	BOOST_TEST((raffer::bit_or(0b01, 0b10) == 0b11));
	BOOST_TEST((raffer::bit_or(0b01, 0b11) == 0b11));
	BOOST_TEST((raffer::bit_or(0b10, 0b00) == 0b10));
	BOOST_TEST((raffer::bit_or(0b10, 0b01) == 0b11));
	BOOST_TEST((raffer::bit_or(0b10, 0b10) == 0b10));
	BOOST_TEST((raffer::bit_or(0b10, 0b11) == 0b11));
	BOOST_TEST((raffer::bit_or(0b11, 0b00) == 0b11));
	BOOST_TEST((raffer::bit_or(0b11, 0b01) == 0b11));
	BOOST_TEST((raffer::bit_or(0b11, 0b10) == 0b11));
	BOOST_TEST((raffer::bit_or(0b11, 0b11) == 0b11));
}


BOOST_AUTO_TEST_CASE(bit_nand)
{
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b00, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b00, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b00, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b00, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b01, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b01, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b01, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b01, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b10, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b10, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b10, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b10, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b11, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b11, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b11, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nand(0b11, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
}


BOOST_AUTO_TEST_CASE(bit_nor)
{
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b00, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b11)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b00, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b00, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b00, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b01, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b01, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b10)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b01, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b01, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b10, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b10, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b10, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b01)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b10, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b11, 0b00)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b11, 0b01)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b11, 0b10)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
	BOOST_TEST((static_cast<unsigned int>(raffer::bit_nor(0b11, 0b11)) == ((static_cast<unsigned int>(~0b0) << 0x2) | 0b00)));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201702L
