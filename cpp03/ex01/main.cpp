#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");

	std::cout << std::endl;
	clap.attack(trap.getName());
	trap.takeDamage(clap.getDamages());

	std::cout << std::endl;
	trap.attack(clap.getName());
	clap.takeDamage(trap.getDamages());

	std::cout << std::endl;
	trap.beRepaired(5);

	std::cout << std::endl;
	ScavTrap	scav("Scav");

	std::cout << std::endl;
	scav.attack(clap.getName());
	clap.takeDamage(scav.getDamages());
	scav.guardGate();
	trap.attack(scav.getName());
	scav.attack(trap.getName());
	trap.takeDamage(scav.getDamages());
	return 0;
}
