#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

class	NoOccurenceFoundException : public std::exception {
	public:
		const char*	what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T & container, int ref);

# include "easyfind.tpp"

#endif
