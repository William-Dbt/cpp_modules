#include <iostream>
#include "Zombie.hpp"
#include "Zombie.h"

static bool	isStrEmpty(std::string str);

Zombie::Zombie() : _name("Unnamed") {}

Zombie::Zombie(std::string name) {
	if (isStrEmpty(name) || name.empty())
		this->_name = "Unnamed";
	else
		this->_name = name;
}

Zombie::~Zombie() {
	std::cout << this->_name << ": died." << std::endl;
}

static bool	isStrEmpty(std::string str) {
	if (str.empty())
		return true;
	for (int i = 0; i <= (int)str.size(); i++)
		if (!isspace(str[i]))
			return false;

	return true;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}