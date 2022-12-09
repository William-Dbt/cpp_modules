#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Constructor Cat is called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat") {
	this->_brain = new Brain();
	*this = cat;
	std::cout << "Constructor Cat by copy is called." << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Destructor Cat is called." << std::endl;
}

Cat&	Cat::operator=(const Cat &cat) {
	std::cout << "Copy assigment Cat is called." << std::endl;
	if (this != &cat) {
		this->_type = cat._type;
		*this->_brain = *cat.getBrain();
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miaouw" << std::endl;
}

Brain*	Cat::getBrain() const {
	return this->_brain;
}
