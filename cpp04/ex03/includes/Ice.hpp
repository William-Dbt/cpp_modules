#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"

class	Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const & ref);
		~Ice();

		Ice&	operator=(Ice const & ref);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter &target);
};

#endif
