#include <stack>

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & ref) : std::stack<T>(ref) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const & ref) {
	if (*this != ref)
		this = std::stack<T>::operator=(ref);

	return *this;
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rbegin() {
	return std::stack<T>::c.rbegin();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rend() {
	return std::stack<T>::c.rend();
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin() {
	return std::stack<T>::c.cbegin();
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend() {
	return std::stack<T>::c.cend();
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator	MutantStack<T>::crbegin() {
	return std::stack<T>::c.crbegin();
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator	MutantStack<T>::crend() {
	return std::stack<T>::c.crend();
}

