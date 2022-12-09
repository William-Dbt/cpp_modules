#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const & type) : AMateria(type) {}

Cure::Cure(Cure const & ref) : AMateria(ref.getType()) {}

Cure::~Cure() {}

Cure&	Cure::operator=(Cure const & ref) {
	if (this != &ref)
		this->_type = ref.getType();

	return *this;
}

AMateria*	Cure::clone() const {
	return (new Cure(this->getType()));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
