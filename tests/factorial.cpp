#include <boost/test/unit_test.hpp>

int factorial(int number) {
	return number > 1 ? factorial(number - 1) * number : 1;
}

BOOST_AUTO_TEST_CASE(first_test) {
	BOOST_TEST(factorial(0) == 1);
	BOOST_TEST(factorial(1) == 1);
	BOOST_TEST(factorial(2) == 2);
	BOOST_TEST(factorial(3) == 6);
	BOOST_TEST(factorial(10) == 3628800);
}
