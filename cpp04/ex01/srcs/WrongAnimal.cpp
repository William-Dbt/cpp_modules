#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "Constructor WrongAnimal is called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Constructor WrongAnimal is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cWrongAnimal) {
	*this = cWrongAnimal;
	std::cout << "Constructor by copy WrongAnimal is called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor WrongAnimal is called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &cWrongAnimal) {
	if (this != &cWrongAnimal)
		this->_type = cWrongAnimal._type;

	return *this;
}

std::string	WrongAnimal::getType() const {
	return _type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "(Wrong)*Undefined sound heard far away...*" << std::endl;
}
