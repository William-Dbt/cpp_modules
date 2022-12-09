#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Constructor WrongCat is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal("WrongCat") {
	*this = wrongCat;
	std::cout << "Constructor WrongCat by copy is called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor WrongCat is called." << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &wrongCat) {
	if (this != &wrongCat)
		this->_type = wrongCat._type;

	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "(Wrong)Miaouw" << std::endl;
}
