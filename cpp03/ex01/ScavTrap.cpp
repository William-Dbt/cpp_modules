#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed") {
	this->_health = 100;
	this->_energy = 50;
	this->_damages = 20;
	std::cout << "ClapTrap " << this->_name << " has evolved in ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_health = 100;
	this->_energy = 50;
	this->_damages = 20;
	std::cout << "ClapTrap " << this->_name << " has evolved in ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &clTrap) : ClapTrap(clTrap._name) {
	*this = clTrap;
	std::cout << "ScavTrap " << this->_name << " is connected. (Copied from the other " << clTrap._name << ')' << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is disconnected." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &clTrap) {
	if (this != &clTrap) {
		this->_name = clTrap._name;
		this->_health = clTrap._health;
		this->_energy = clTrap._energy;
		this->_damages = clTrap._damages;
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_health == 0)
		return ;

	if (this->_energy == 0) {
		std::cout << "ScavTrap " << this->_name << " is tired, he have to go to sleep!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " use his weapon on " << target << ", causing " << this->_damages << " points of damage!" << std::endl;
	this->_energy--;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now on guard gate!" << std::endl;
	std::cout << '-' << this->_name << ": YOU SHOULD NOT PASS!" << std::endl;
}
