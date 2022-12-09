#include <iostream>
#include <string>
#include "whatever.hpp"

int	main() {
	std::cout << "Template test with std::string:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		std::string	tmp0 = "Hello, I'm toto!";
		std::string	tmp1 = "!otot m'I olleH";

		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		std::cout << "Calling swap function:" << std::endl;
		::swap(tmp0, tmp1);
		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		tmp0 = "012345";
		tmp1 = "0123456";
		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		std::cout << "Calling max and min functions:" << std::endl;
		std::cout << "Min: " << ::min(tmp0, tmp1) << std::endl;
		std::cout << "Max: " << ::max(tmp0, tmp1) << std::endl;
	}
	std::cout << "-------------------------" << std::endl << std::endl;

	std::cout << "Template test with double:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		double	tmp0 = 42.42;
		double	tmp1 = -42.42;

		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		std::cout << "Calling swap function:" << std::endl;
		::swap(tmp0, tmp1);
		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		tmp0 = 1900.18;
		tmp1 = 1900.14;
		std::cout << "tmp0: " << tmp0 << std::endl;
		std::cout << "tmp1: " << tmp1 << std::endl << std::endl;

		std::cout << "Calling max and min functions:" << std::endl;
		std::cout << "Min: " << ::min(tmp0, tmp1) << std::endl;
		std::cout << "Max: " << ::max(tmp0, tmp1) << std::endl;
	}
	std::cout << "-------------------------" << std::endl << std::endl;

	std::cout << "Subject main tests:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		int	a = 2;
		int	b = 3;
		
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	return 0;
}
