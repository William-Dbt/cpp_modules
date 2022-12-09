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
	std::cout << "Copy assigment Animal is called." << std::endl;
	if (this != &cAnimal) {
		this->_type = cAnimal._type;
		*this->getBrain() = *cAnimal.getBrain();
	}

	return *this;
}

std::string	Animal::getType() const {
	return _type;
}

void	Animal::makeSound() const {
	std::cout << "*Undefined sound heard far away...*" << std::endl;
}

Brain*	Animal::getBrain() const {
	return 0;
}
