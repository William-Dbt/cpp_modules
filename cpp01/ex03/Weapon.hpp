#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class	Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		std::string const	&getType() const;
		void			setType(std::string newType);

	private:
		std::string	_type;
};

#endif