#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Constructor Dog is called." << std::endl;
}

Dog::Dog(const Dog &dog) : Animal("Dog") {
	*this = dog;
	std::cout << "Constructor Dog by copy is called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Destructor Dog is called." << std::endl;
}

Dog&	Dog::operator=(const Dog &dog) {
	if (this != &dog)
		this->_type = dog._type;

	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf ouaf" << std::endl;
}
