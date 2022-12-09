#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat);
		virtual	~Cat();

		Cat&			operator=(const Cat &cat);

		virtual Brain*	getBrain() const;
		virtual	void	makeSound() const;

	private:
		Brain*	_brain;
};

#endif
