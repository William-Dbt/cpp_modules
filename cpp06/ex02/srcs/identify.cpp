#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	static bool	seedGenerated = false;

	if (!seedGenerated) {
		srand(time(NULL));
		seedGenerated = true;
	}
	switch (rand() % 3 + 1) {
		case 1:
			return dynamic_cast<Base*>(new A());

		case 2:
			return dynamic_cast<Base*>(new B());

		case 3:
			return dynamic_cast<Base*>(new C());

		default:
			std::cerr << "Random failed!" << std::endl;
	}
	return NULL;
}

// Dynamic cast return NULL when casts a pointer
void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else if (dynamic_cast<Base*>(p) != NULL)
		std::cout << "Base" << std::endl;
	else
		std::cerr << "Identify error!" << std::endl;
}

// Dynamic cast throw a bad_cast exception when cast failed with reference.
void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e) {}

	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &e) {}

	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &e) {}
}
