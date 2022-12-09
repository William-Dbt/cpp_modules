#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _health(10), _energy(10), _damages(0) {
	std::cout << "ClapTrap " << this->_name << " is connected." << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _health(10), _energy(10), _damages(0)
{
	std::cout << "ClapTrap " << this->_name << " is connected." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clTrap) {
	*this = clTrap;

	std::cout << "ClapTrap " << this->_name << " is connected. (Copied from the other " << clTrap._name << ')' << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is disconnected." << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &clTrap) {
	if (this != &clTrap) {
		this->_name = clTrap._name;
		this->_health = clTrap._health;
		this->_energy = clTrap._energy;
		this->_damages = clTrap._damages;
	}
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (this->_health == 0)
		return ;

	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " is tired, he can't even attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damages << " points of damage!" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_health == 0)
		return ;

	if ((int)(this->_health - amount) < 0)
		this->_health = 0;
	else
		this->_health -= amount;

	std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage." << std::endl;
	if (this->_health == 0)
		std::cout << "OHH NOO! " << this->_name << " just died!" << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_health == 0)
		return ;

	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " is out of energy, it can't be repaired!" << std::endl;
		return ;
	}
	this->_health += amount;
	std::cout << "ClapTrap " <<  this->_name << " has been repaired and gain " << amount << " health point!" << std::endl;
	this->_energy--;
}

unsigned int	ClapTrap::getDamages() const {
	return this->_damages;
}

std::string	ClapTrap::getName() const{
	return this->_name;
}
