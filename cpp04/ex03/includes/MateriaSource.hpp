#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#define MATSLOTS_SIZE	4

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "MateriaList.hpp"

class	MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & ref);
		~MateriaSource();

		MateriaSource&	operator=(MateriaSource const & ref);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const & type);

	private:
		AMateria	*slots[MATSLOTS_SIZE];
		MateriaList	materiaGarbage;
};

#endif