#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << std::endl;
	std::cout << cat->getType() << " : ";
	cat->makeSound();
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << animal->getType() << " : ";
	animal->makeSound();

	std::cout << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << std::endl;
	std::cout << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << " : ";
	wrongCat->makeSound();

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl;
	delete wrongAnimal;
	delete wrongCat;
	
	return 0;
}
