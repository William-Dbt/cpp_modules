#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class	Cure : public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const & ref);
		~Cure();

		Cure&	operator=(Cure const & ref);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter &target);
};

#endif
