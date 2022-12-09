#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>
# include "ICharacter.hpp"

class	AMateria {
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & ref);
		virtual ~AMateria();

		AMateria&	operator=(AMateria const & ref);
		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string	_type;
};

#endif
