#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::Ice(Ice const & ref) : AMateria(ref.getType()) {}

Ice::~Ice() {}

Ice&	Ice::operator=(Ice const & ref) {
	if (this != &ref)
		this->_type = ref.getType();
	
	return *this;
}

AMateria*	Ice::clone() const {
	return (new Ice(this->getType()));
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
