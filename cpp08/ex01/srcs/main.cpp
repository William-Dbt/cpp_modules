#include <iostream>
#include <ctime>
#include "Span.hpp"

static void	constructorTests() {
	std::cout << "Test span constructors:" << std::endl << std::endl;
	std::cout << "Fill a span of size 5 and try to fill the 6th element:" << std::endl;
	Span	span0(5);

	span0.addNumber(18);
	span0.addNumber(36);
	span0.addNumber(72);
	span0.addNumber(144);
	span0.addNumber(288);
	std::cout << "Span0: ";
	span0.showArray();
	try {
		std::cout << "Add the 6th element: ";
		span0.addNumber(576);
		std::cerr << "error: exception (6th element)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Test with default constructor:" << std::endl;
	Span	span1;

	try {
		std::cout << "Try to add en element: ";
		span1.addNumber(42);
		std::cerr << "error: exception (0 element)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Tests with copy constructor and operator =:" << std::endl;
	Span	span2;

	std::cout << "Span0: ";
	span0.showArray();
	std::cout << std::endl;

	std::cout << "Assign span0 to span2:" << std::endl;
	span2 = span0;
	std::cout << "Span2: ";
	span2.showArray();
	std::cout << std::endl;

	std::cout << "And span 3 with constructor by copy:" << std::endl;
	Span	span3(span2);

	std::cout << "Span3: ";
	span3.showArray();
}

static void	spanTests() {
	std::cout << "Test span functions:" << std::endl << std::endl;
	Span	span0(5);

	std::cout << "Try to get longest span while no span is added: ";
	try {
		span0.longestSpan();
		std::cerr << "error: exception (longestSpan: no span)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Add one element in span and test: ";
	span0.addNumber(42);
	try {
		span0.shortestSpan();
		std::cerr << "error: exception (shortestSpan: no span)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Add more elements in span0 and get shortest and longest span:" << std::endl;
	span0.addNumber(97);
	span0.addNumber(13);
	span0.addNumber(75);
	span0.addNumber(22);
	// span0: 42, 97, 13, 75, 22
	std::cout << "Span0: ";
	span0.showArray();
	std::cout << "Shortest span: " << span0.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span0.longestSpan() << std::endl;

	std::cout << std::endl << "Test with 10 000 elements (lol): " << std::endl;
	Span		monster(10000);
	int			tmp;
	static int	seedGenerated = false;

	if (!seedGenerated) {
		srand(time(NULL));
		seedGenerated = true;
	}
	for (int i = 0; i < 10000; i++) {
		tmp = rand() % 100000 + 1;
		monster.addNumber(tmp);
	}
	std::cout << "Shortest span: " << monster.shortestSpan() << std::endl;
	std::cout << "Longest span: " << monster.longestSpan() << std::endl;
}

static void	addIteratorTests() {
	Span						span(8);
	std::vector<unsigned int>	vec;

	std::cout << "Init span of 8 and create a std::vector which contains 5, 85, 1245, 0, 42" << std::endl;
	vec.push_back(5);
	vec.push_back(85);
	vec.push_back(1245);
	vec.push_back(0);
	vec.push_back(42);
	std::cout << "Then call addNumber() with iterators on std::vector and print the span:" << std::endl;
	span.addNumber(vec.begin(), vec.end());
	std::cout << "Span: ";
	span.showArray();

	std::cout << std::endl << "Try to re-add std::vector to span (should throw exception):" << std::endl;
	try {
		span.addNumber(vec.begin(), vec.end());
		std::cerr << "error: exception: addNumber Iterator" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Try to add a vector of 3 elements on span (should work):" << std::endl;
	std::vector<unsigned int>	vec1;

	vec1.push_back(18);
	vec1.push_back(52);
	vec1.push_back(84);
	std::cout << "Vec 1 is: {18, 52, 84}" << std::endl << std::endl;
	span.addNumber(vec1.begin(), vec1.end());
	std::cout << "Span: ";
	span.showArray();

	std::cout << std::endl << "Try to add more:" << std::endl;
	try {
		span.addNumber(vec1.begin(), vec1.end());
		std::cerr << "error: exception: more vec (> 8)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

int	main() {
	std::cout << "--------------------" << std::endl;
	constructorTests();
	std::cout << std::endl << "--------------------" << std::endl << std::endl;
	spanTests();
	std::cout << std::endl << "--------------------" << std::endl << std::endl;
	addIteratorTests();
	std::cout << "--------------------" << std::endl;
}
