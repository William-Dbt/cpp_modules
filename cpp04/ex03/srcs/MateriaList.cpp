#include <iostream>
#include "MateriaList.hpp"

MateriaList::MateriaList() {
	this->node = NULL;
}

MateriaList::MateriaList(MateriaList const & ref) {
	*this = ref;
}

MateriaList::~MateriaList () {
	t_list	*tmp;
	t_list	*next;

	if (this->node == NULL)
		return ;

	tmp = this->node;
	while (tmp != NULL) {
		next = tmp->next;
		delete tmp;
		tmp = next;
	}
}

MateriaList&	MateriaList::operator=(MateriaList const & ref) {
	t_list	*tmp;

	tmp = ref.node;
	while (tmp != NULL) {
		this->node = tmp;
		tmp = tmp->next;
	}
	return *this;
}

t_list*	newListItem(AMateria* materia) {
	t_list	*buffer = new t_list;

	buffer->materia = materia;
	buffer->next = NULL;
	return buffer;
}

bool	MateriaList::isMateriaAlreadySaved(AMateria& materia) {
	t_list	*tmp;

	tmp = this->node;
	while (tmp) {
		if (tmp->materia == &materia)
			return true;
		
		tmp = tmp->next;
	}
	return false;
}

void	MateriaList::addMateria(AMateria* materia) {
	t_list	*tmp;

	if (this->isMateriaAlreadySaved(*materia))
		return ;

	tmp = this->node;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;

	if (tmp == NULL)
		this->node = newListItem(materia);
	else
		tmp->next = newListItem(materia);
}
