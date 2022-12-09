#include <iostream>
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	int				i;
	IMateriaSource* src = new MateriaSource();
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();
	AMateria		*newIce = new Ice("newIce");

	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(newIce);

	std::cout << "***************" << std::endl;
	std::cout << "Learn more than " << MATSLOTS_SIZE << " materias:" << std::endl;
	// loop while MATSLOTS_SIZE is reached (materiasource's slots is full)
	for (i = 3; i < MATSLOTS_SIZE; i++)
		src->learnMateria(cure);

	// the overflow one:
	src->learnMateria(cure);

	std::cout << std::endl << "NULL ptr materia:" << std::endl;
	src->learnMateria(NULL);

	std::cout << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "Equip more than " << SLOTS_SIZE << " materias:" << std::endl;
	// loop while SLOTS_SIZE is reached (character's slots is full)
	for (i = 4; i < SLOTS_SIZE; i++)
		me->equip(tmp);
	
	// equip one more materia to overflow the maximum slots authorized
	// use newUse to check valgrind leaks (he's not saved in any character's slot)
	tmp = src->createMateria("newIce");
	me->equip(tmp);

	std::cout << std::endl << "NULL ptr equip:" << std::endl;
	me->equip(NULL);

	std::cout << std::endl << "Create materia doesn't match any type:" << std::endl;
	tmp = src->createMateria("concrete");
	std::cout << "***************" << std::endl;

	std::cout << std::endl << "Main subject part:" << std::endl;
	ICharacter* bob = new Character("bob");
	
	std::cout << std::endl;
	for (i = 0; i < SLOTS_SIZE; i++)
		me->use(i, *bob);

	std::cout << std::endl << "***************" << std::endl;
	
	std::cout << "Character's use function overflow slot size:" << std::endl;
	me->use(-1, *bob);
	me->use(SLOTS_SIZE, *bob);

	// Unequip materia at slot 2
	me->unequip(2);
	std::cout << std::endl << "Use unequiped materia:" << std::endl;
	me->use(2, *bob);

	delete newIce;
	delete ice;
	delete cure;
	delete bob;
	delete me;
	delete src;
	return 0; 
}
