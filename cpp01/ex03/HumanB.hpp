#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include <string>
# include "Weapon.hpp"

class	HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &weapon);

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif