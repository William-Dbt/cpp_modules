#ifndef __MATERIALIST_HPP__
# define __MATERIALIST_HPP__

# include "AMateria.hpp"

typedef struct s_list	t_list;

struct s_list {
	AMateria	*materia;
	t_list		*next;
};

class	MateriaList {
	public:
		MateriaList();
		MateriaList(MateriaList const & ref);
		~MateriaList();

		MateriaList&	operator=(MateriaList const & ref);

		bool	isMateriaAlreadySaved(AMateria& materia);
		void	addMateria(AMateria* materia);

	private:
		t_list	*node;
};

#endif
