#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat);
		virtual	~Cat();

		Cat&	operator=(const Cat &cat);
		virtual	void	makeSound() const;
};

#endif
