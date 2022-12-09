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
		for (int i = 0; i < NUM_IDEAS; i++)
			this->_ideas[i] = brain._ideas[i];

	return *this;
}

void	Brain::showIdeas() const {
	for (int i = 0; i < NUM_IDEAS; i++) {
		if (!this->_ideas[i].size())
			continue ;
		else
			std::cout << i << ": " << this->_ideas[i] << std::endl;
	}
}

void	Brain::setIdea(int idx, std::string idea) {
	if (idx < 0 || idx >= NUM_IDEAS) {
		std::cout << "setIdea: Invalid index! Must be between 0 and " << NUM_IDEAS << "!" << std::endl;
		return ;
	}
	if (idea.empty() || !idea.size()) {
		std::cout << "setIdea: Nothing to append in the ideas!" << std::endl;
		return ;
	}
	this->_ideas[idx] = idea;
}
