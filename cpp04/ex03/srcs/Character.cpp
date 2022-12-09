#include <iostream>
#include "Character.hpp"

Character::Character() : _name("Unnamed") {
	for (int i = 0; i < SLOTS_SIZE; i++)
		this->slots[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < SLOTS_SIZE; i++)
		this->slots[i] = NULL;
}

Character::Character(Character const & ref) {
	int	i;

	this->_name = ref.getName();
	for (i = 0; i < SLOTS_SIZE; i++) {
		if (ref.slots[i] != NULL)
			this->slots[i] = ref.slots[i];
		else
			this->slots[i] = NULL;
	}
}

Character::~Character() {}

std::string const &	Character::getName() const {
	return this->_name;
}

int	Character::getAvailableSlot() const {
	for (int i = 0; i < SLOTS_SIZE; i++)
		if (this->slots[i] == NULL)
			return i;

	return -1;
}

void	Character::showInventory() const {
	std::cout << this->getName() << "'s inventory: " << std::endl;
	for (int i = 0; i < SLOTS_SIZE; i++)
		std::cout << i << ": " << this->slots[i]->getType() << std::endl;
	
	std::cout << std::endl;
}

void	Character::equip(AMateria* m) {
	int	slot;

	if (m == NULL) {
		std::cout << "Unknow materia to equip!" << std::endl;
		return ;
	}

	slot = this->getAvailableSlot();
	if (slot == -1) {
		std::cout << "Can't equip " << m->getType() << " on " << this->getName() << "! His inventory is full!" << std::endl;
		return ;
	}
	this->slots[slot] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= SLOTS_SIZE) {
		std::cout << "unequip: Invalid index! Must be between 0 and " << SLOTS_SIZE - 1 << std::endl;
		return ;
	}
	if (this->slots[idx] == NULL) {
		std::cout << "Can't unequip weapon that doesn't exist!" << std::endl;
		return ;
	}

	this->slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= SLOTS_SIZE) {
		std::cout << "use: Invalid index! Must be between 0 and " << SLOTS_SIZE - 1 << std::endl;
		return ;
	}
	if (this->slots[idx] == NULL) {
		std::cout << "Can't use weapon that doesn't exist!" << std::endl;
		return ;
	}

	this->slots[idx]->use(target);
}
