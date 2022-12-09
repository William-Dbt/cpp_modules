#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <string>

class	Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	setName(std::string name);
		void	announce(void);

	private:
		std::string	_name;
};

#endif