#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define TABSIZE	5

int	main() {
	int				i;
	const Animal	*animals[10];
	
	for (i = 0; i < TABSIZE; i++) {
		if (i < TABSIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (i = 0; i < TABSIZE; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	Animal	*dog = new Dog();

	if (dog->getBrain()) {
		std::cout << std::endl;
		std::cout << "-- Adding ideas to dog brain and print them" << std::endl;
		dog->getBrain()->_ideas[0] = "Buy another phone";
		dog->getBrain()->_ideas[1] = "Start gym";
		dog->getBrain()->_ideas[2] = "Repair the TV instead of buying one";
		dog->getBrain()->showIdeas();
	}

	std::cout << std::endl;
	std::cout << "-- Create a cat by calling Animal class, as Dog before" << std::endl;
	Animal	*cat = new Cat();

	if (cat->getBrain()) {
		std::cout << std::endl;
		std::cout << "-- Set first idea for the cat and print the idea" << std::endl;
		cat->getBrain()->_ideas[0] = "Idea old cat 0";
		cat->getBrain()->showIdeas();
	}

	std::cout << std::endl;
	std::cout << "-- Assign the cat to the dog (*cat = *dog)" << std::endl;
	*cat = *dog;
	if (cat->getBrain()) {
		std::cout << "-- Print ideas of the cat" << std::endl;
		cat->getBrain()->showIdeas();
	}

	std::cout << std::endl;
	delete dog;
	delete cat;

	return 0;
}
