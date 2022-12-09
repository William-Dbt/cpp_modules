#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &cWrongAnimal);
		~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal &cWrongAnimal);
		std::string	getType() const;

		void		makeSound() const;

	protected:
		std::string	_type;
};

#endif
