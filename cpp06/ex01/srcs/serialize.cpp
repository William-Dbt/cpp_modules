#include <iostream>
#include "serialize.hpp"

uintptr_t	serialize(Data* ptr) {
	if (ptr == 0)
		return 0;

	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw) {
	if (raw == 0)
		return NULL;

	return reinterpret_cast<Data*>(raw);
}
