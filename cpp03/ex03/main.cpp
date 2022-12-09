#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	FragTrap	frag("Frag");

	std::cout << std::endl;
	frag.attack(scav.getName());
	scav.takeDamage(frag.getDamages());
	scav.attack(frag.getName());
	frag.takeDamage(scav.getDamages());

	std::cout << std::endl << "..." << std::endl;
	std::cout << "-Scav: Dude what are you doing? We are strong together, help me to keep this gate!" << std::endl;
	std::cout << "-Frag: ... Ok!" << std::endl;
	scav.beRepaired(frag.getDamages());
	frag.beRepaired(scav.getDamages());
	frag.highFivesGuys();
	std::cout << "-Scav&Frag: ┏(＾0＾)┛┗(＾0＾) ┓" << std::endl;

	std::cout << std::endl;
	DiamondTrap	diamond("Diamond");

	std::cout << std::endl;
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();
	
	std::cout << std::endl;
	scav.attack(diamond.getName());
	diamond.takeDamage(scav.getDamages());

	int	i = 0;
	for (i = 0; i < 4; i++) {
		diamond.attack(scav.getName());
		scav.takeDamage(diamond.getDamages());
	}
	diamond.beRepaired(scav.getDamages());
	diamond.highFivesGuys();

	std::cout << std::endl;
	frag.attack(diamond.getName());
	diamond.takeDamage(frag.getDamages());
	for (i = 0; i < 4; i++) {
		diamond.attack(frag.getName());
		frag.takeDamage(diamond.getDamages());
	}

	std::cout << std::endl;
	return 0;
}
