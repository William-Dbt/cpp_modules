#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap::ClapTrap("_clap_name") {
	_name = "Unnamed";
	this->FragTrap::_health = 100;
	this->ScavTrap::_energy = 50;
	this->FragTrap::_damages = 30;
	std::cout << "DiamondTrap " << _name << " has appeared!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap::ClapTrap(name + "_clap_name") {
	_name = name;
	this->FragTrap::_health = 100;
	this->ScavTrap::_energy = 50;
	this->FragTrap::_damages = 30;
	std::cout << "DiamondTrap " << _name << " has appeared!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &dmTrap) : FragTrap::ClapTrap(dmTrap._name) {
	if (this != &dmTrap)
		*this = dmTrap;
	std::cout << "DiamondTrap has spawn and mimic " << dmTrap.FragTrap::getName() << '!' << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is disconnected." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &dmTrap) {
	if (this != &dmTrap) {
		this->_name = dmTrap._name;
		this->FragTrap::_health = dmTrap.FragTrap::_health;
		this->ScavTrap::_energy = dmTrap.ScavTrap::_energy;
		this->FragTrap::_damages = dmTrap.FragTrap::_damages;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const &target) {
	FragTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "Hi! I'm " << this->_name << " and my clapname is " << this->FragTrap::_name << '!' << std::endl;
}
