#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed") {
	this->_health = 100;
	this->_energy = 100;
	this->_damages = 30;
	std::cout << "ClapTrap " << this->getName() << " has evolved in FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	this->_health = 100;
	this->_energy = 100;
	this->_damages = 30;
	std::cout << "ClapTrap " << this->getName() << " has evolved in FragTrap!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fgTrap) : ClapTrap(fgTrap._name) {
	*this = fgTrap;
	std::cout << "A FragTrap has spawn based of " << fgTrap._name << '!' << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is disconnected." << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const &fgTrap) {
	if (this != &fgTrap) {
		this->_name = fgTrap._name;
		this->_health = fgTrap._health;
		this->_energy = fgTrap._energy;
		this->_damages = fgTrap._damages;
	}
	return *this;
}

void	FragTrap::attack(std::string const &target) {
	if (this->_health == 0)
		return ;

	if (this->_energy == 0) {
		std::cout << "FragTrap " << this->_name << " can't do anything... He's covided." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " shot " << target << ", causing " << this->_damages << " points of damage!" << std::endl;
	this->_energy--;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " Let's highfive?" << std::endl;
}
