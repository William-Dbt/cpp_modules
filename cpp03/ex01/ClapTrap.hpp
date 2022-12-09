#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <string>

class	ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &clTrap);
		~ClapTrap();

		ClapTrap&	operator=(ClapTrap const &clTrap);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getDamages() const;

	protected:
		std::string		_name;

		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damages;
};

#endif
