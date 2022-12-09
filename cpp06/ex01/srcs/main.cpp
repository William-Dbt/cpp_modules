#include <iostream>
#include "serialize.hpp"

int	main() {
	uintptr_t	intptrTmp;
	Data		*dataTmp;
	Data		*data = new Data("games");

	std::cout << *data << std::endl;
	std::cout << "Adress: " << &data << std::endl << std::endl;

	std::cout << "Serialize and deserialize data object and save this in dataTmp" << std::endl;
	intptrTmp = serialize(data);
	dataTmp = deserialize(intptrTmp);
	std::cout << "dataTmp adress of deserialize: " << &dataTmp << std::endl;

	std::cout << std::endl << *dataTmp << std::endl;
	std::cout << &dataTmp << std::endl;
	delete data;
	return 0;
}
