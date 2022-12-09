#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const &fgTrap);
		~FragTrap();

		FragTrap&	operator=(FragTrap const &fgTrap);
		void		highFivesGuys();
		void		attack(std::string const &target);
};

#endif