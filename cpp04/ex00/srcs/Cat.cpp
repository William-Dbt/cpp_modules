#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Constructor Cat is called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat") {
	*this = cat;
	std::cout << "Constructor Cat by copy is called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Destructor Cat is called." << std::endl;
}

Cat&	Cat::operator=(const Cat &cat) {
	if (this != &cat)
		this->_type = cat._type;

	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miaouw" << std::endl;
}
