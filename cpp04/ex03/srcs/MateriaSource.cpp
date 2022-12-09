#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MATSLOTS_SIZE; i++)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & ref) {
	*this = ref;
}

MateriaSource::~MateriaSource() {}

MateriaSource&	MateriaSource::operator=(MateriaSource const & ref) {
	for (int i = 0; i < MATSLOTS_SIZE; i++) {
		if (ref.slots[i] != NULL) {
			this->slots[i] = ref.slots[i]->clone();
			this->materiaGarbage.addMateria(this->slots[i]);
		}
		else
			this->slots[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia) {
	int	i;

	if (!materia) {
		std::cout << "Unknow materia to learn!" << std::endl;
		return ;
	}
	this->materiaGarbage.addMateria(materia);
	for (i = 0; i < MATSLOTS_SIZE; i++)
		if (!this->slots[i])
			break ;

	if (i == MATSLOTS_SIZE) {
		std::cout << "Cannot learn more materias!" << std::endl;
		return ;
	}
	this->slots[i] = materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MATSLOTS_SIZE; i++) {
		if (this->slots[i] && this->slots[i]->getType().compare(type) == 0)
			return this->slots[i];
	}
	std::cout << "Cannot create materia from type " << type << std::endl;
	return 0;
}
