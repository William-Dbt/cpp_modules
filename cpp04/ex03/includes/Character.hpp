#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# define SLOTS_SIZE	4

# include "AMateria.hpp"

class	Character : public ICharacter {
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & ref);
		~Character();

		Character&	operator=(Character const & ref);
		int			getAvailableSlot() const;
		void		showInventory() const;

		virtual std::string const &	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria	*slots[SLOTS_SIZE];
};

#endif
