#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Constructor Brain is called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	*this = brain;
	std::cout << "Constructor by copy of Brain is called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Destructor of Brain is called" << std::endl;
}

Brain&	Brain::operator=(const Brain &brain) {
	std::cout << "Copy assigment Brain is called." << std::endl;
	if (this != &brain)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];

	return *this;
}

void	Brain::showIdeas() const {
	for (int i = 0; i < 100; i++) {
		if (!this->_ideas[i].size())
			continue ;
		else
			std::cout << i << ": " << this->_ideas[i] << std::endl;
	}
}
