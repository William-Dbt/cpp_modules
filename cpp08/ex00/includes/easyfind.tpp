#include <exception>
#include <algorithm>

const char*	NoOccurenceFoundException::what() const throw() {
	return ("No reference has been found!");
}

template <typename T>
typename T::iterator	easyfind(T & container, int ref) {
	typename T::iterator	it;
	
	it = std::find(container.begin(), container.end(), ref);
	if (it != container.end())
		return it;

	throw NoOccurenceFoundException();
}
