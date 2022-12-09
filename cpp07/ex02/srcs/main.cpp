#include <iostream>
#include <cstdlib>
#include "Array.hpp"

// Constructors & Operators tests
static void	firstTest() {
	std::cout << "Create an int array of 10 and fill it in reverse:" << std::endl;
	Array<int>	intArray0(10);

	for (int i = 0; i < (int)intArray0.size(); i++)
		intArray0[i] = 9 - i;

	std::cout << "intArray0: ";
	intArray0.display();

	std::cout << std::endl << "Create an array by copy constructor of intArray0:" << std::endl;
	Array<int>	intArray1(intArray0);

	std::cout << "intArray1: ";
	intArray1.display();

	std::cout << std::endl << "Modify one item and print both array to show their independence:" << std::endl;
	intArray1[5] = 42;
	std::cout << "intArray0: ";
	intArray0.display();
	std::cout << "intArray1: ";
	intArray1.display();

	std::cout << std::endl << "Same thing with copy operator from intArray0:" << std::endl;
	Array<int>	intArray2;

	intArray2 = intArray0;
	intArray2[0] = 999;
	std::cout << "intArray0: ";
	intArray0.display();
	std::cout << "intArray2: ";
	intArray2.display();

	std::cout << std::endl << "Create of array without size (call default constructor) and try to fill the first element:" << std::endl;
	Array<int>	intArray3;

	std::cout << "Array size (intArray3): " << intArray3.size() << std::endl;
	try {
		std::cout << "Try to fill the first element:" << std::endl;
		intArray3[0] = 0;
		std::cerr << "error: exception: intArray3" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

// Indexs and Array access test
static void	secondTest() {
	int	i;

	std::cout << "Create an int array of 5 and fill it:" << std::endl;
	Array<int>	intArray0(5);

	for (i = 0; i < (int)intArray0.size(); i++)
		intArray0[i] = i;

	std::cout << "intArray0: ";
	intArray0.display();

	std::cout << std::endl << "Try to increment all values:" << std::endl;
	for (i = 0; i < (int)intArray0.size(); i++)
		intArray0[i] += 1;

	std::cout << "intArray0: ";
	intArray0.display();

	std::cout << std::endl << "Try to access index -1 and 5 (array limits):" << std::endl;
	try {
		std::cout << "Index -1:" << std::endl;
		intArray0[-1] = 0;
		std::cerr << "-1: exception error" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Index 5:" << std::endl;
		intArray0[5] = 0;
		std::cerr << "5: exception error" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Try to access to a array of 0 elements:" << std::endl;
	Array<int>	intArray1(0);

	try {
		std::cout << intArray1[0] << std::endl;
		std::cerr << "0: exception error" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

static void	fourthTest() {
	std::cout << "Create a string array of 5 names:" << std::endl;
	Array<std::string>	names(5);

	names[0] = "Julien";
	names[1] = "Xavier";
	names[2] = "Elena";
	names[3] = "Tristan";
	names[4] = "Romane";
	names.display();

	std::cout << std::endl << "Try to change the name of Xavier(1):" << std::endl;
	names[1] = "Toto";
	names.display();

	std::cout << std::endl << "Iter on all element and add a ~ in their names:" << std::endl;
	for (int i = 0; i < (int)names.size(); i++)
		names[i].append("~");
	
	names.display();
}

int	main(int argc, char **argv) {
	int	testNumber;

	if (argc != 2) {
		std::cout << "Usage: ./ex02 <test number>" << std::endl;
		std::cout << "-> 0: Constructors & Operators" << std::endl;
		std::cout << "-> 1: Indexes and Array Access" << std::endl;
		std::cout << "-> 2: Size function test" << std::endl;
		std::cout << "-> 3: More types array test" << std::endl;
		return 1;
	}
	testNumber = atoi(argv[1]);
	switch(testNumber) {
		case 0: {
			firstTest();
			break ;
		}
		case 1: {
			secondTest();
			break ;
		}
		case 2: {
			std::cout << "Get the size of an int array of 18 elements:" << std::endl;
			Array<int>	intArray0(18);
			std::cout << "intArray0: ";
			std::cout << intArray0.size() << std::endl << std::endl;

			std::cout << "Get the size of and string array of 22 elements:" << std::endl;
			Array<std::string>	strArray0(22);
			std::cout << "strArray0: ";
			std::cout << strArray0.size() << std::endl;
			break ;
		}
		case 3: {
			fourthTest();
			break ;
		}
		default:
			std::cerr << "No test found. Please enter a valid test number." << std::endl;
	}
}
