#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class	Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &cAnimal);
		virtual	~Animal();

		Animal&		operator=(const Animal &cAnimal);
		std::string	getType() const;

		virtual	void	makeSound() const;

	protected:
		std::string	_type;
};

#endif
