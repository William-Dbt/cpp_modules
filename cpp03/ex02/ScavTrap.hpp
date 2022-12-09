#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &clTrap);
		~ScavTrap();
		
		ScavTrap&	operator=(const ScavTrap &clTrap);
		void		guardGate();
		void		attack(const std::string &target);
};

#endif