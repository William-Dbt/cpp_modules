#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog);
		virtual	~Dog();

		Dog&	operator=(const Dog &dog);
		virtual	void	makeSound() const;
};

#endif
