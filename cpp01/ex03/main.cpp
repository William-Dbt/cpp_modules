#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "First part:" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl << "Second part:" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl << "Third part:" << std::endl;
	{
		Weapon	m4a1 = Weapon("M4A1");
		HumanB	toto("Toto");

		toto.attack();
		toto.setWeapon(m4a1);
		toto.attack();
	}
	return 0;
}