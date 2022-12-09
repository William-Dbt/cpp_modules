#include <iostream>
#include "identify.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define NUMBER_TESTS	10

int	main() {
	Base	*tmp;

	std::cout << "Tests with pointer identify:" << std::endl;
	for (int i = 0; i < NUMBER_TESTS; i++) {
		std::cout << i << ": ";
		tmp = generate();
		identify(tmp);
		// tmp->getType();
	}

	std::cout << std::endl << "Tests with reference identify:" << std::endl;
	for (int i = 0; i < NUMBER_TESTS; i++) {
		std::cout << i << ": ";
		tmp = generate();
		identify(*tmp);
		// tmp->getType();
	}
	return 0;
}
