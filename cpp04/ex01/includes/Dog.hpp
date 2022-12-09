#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog);
		virtual	~Dog();

		Dog&			operator=(const Dog &dog);

		virtual Brain*	getBrain() const;
		virtual	void	makeSound() const;

	private:
		Brain*	_brain;
};

#endif
