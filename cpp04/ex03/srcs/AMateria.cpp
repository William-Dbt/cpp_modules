#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : _type("Unknow") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & ref) {
	*this = ref;
}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(AMateria const & ref) {
	if (this != &ref)
		this->_type = ref.getType();

	return *this;
}

std::string const &	AMateria::getType() const {
	return this->_type;
}

void	AMateria::use(ICharacter &target) {
	std::cout << target.getName() << " uses the first materia founded on the floor!" << std::endl;
}
