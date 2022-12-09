#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Constructor Dog is called." << std::endl;
}

Dog::Dog(const Dog &dog) : Animal("Dog") {
	this->_brain = new Brain();
	*this = dog;
	std::cout << "Constructor Dog by copy is called." << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Destructor Dog is called." << std::endl;
}

Dog&	Dog::operator=(const Dog &dog) {
	std::cout << "Copy assigment Dog is called." << std::endl;
	if (this != &dog) {
		this->_type = dog._type;
		*this->_brain = *dog.getBrain();
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf ouaf" << std::endl;
}

Brain*	Dog::getBrain() const {
	return this->_brain;
}
