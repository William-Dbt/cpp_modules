#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

std::string const	&Weapon::getType() const {
	return this->_type;
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}