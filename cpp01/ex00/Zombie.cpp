#include <iostream>
#include "Zombie.hpp"
#include "Zombie.h"

static bool	isStrEmpty(std::string str);

Zombie::Zombie() : _name("Unnamed") {}

Zombie::Zombie(std::string name) {
	if (isStrEmpty(name) || name.empty())
		_name = "Unnamed";
	else
		_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << ": died." << std::endl;
}

static bool	isStrEmpty(std::string str) {
	if (str.empty())
		return true;
	for (int i = 0; i <= (int)str.size(); i++)
		if (!isspace(str[i]))
			return false;

	return true;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}