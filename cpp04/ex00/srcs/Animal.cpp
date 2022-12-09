#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Constructor Animal is called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Constructor Animal is called." << std::endl;
}

Animal::Animal(const Animal &cAnimal) {
	*this = cAnimal;
	std::cout << "Constructor by copy Animal is called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor Animal is called." << std::endl;
}

Animal&	Animal::operator=(const Animal &cAnimal) {
	if (this != &cAnimal)
		this->_type = cAnimal._type;

	return *this;
}

std::string	Animal::getType() const {
	return _type;
}

void	Animal::makeSound() const {
	std::cout << "*Undefined sound heard far away...*" << std::endl;
}
