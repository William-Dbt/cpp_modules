#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &dmTrap);
		~DiamondTrap();

		DiamondTrap&	operator=(DiamondTrap const &dmTrap);
		void			attack(std::string const &target);
		void			whoAmI();

	private:
		std::string	_name;
};

#endif