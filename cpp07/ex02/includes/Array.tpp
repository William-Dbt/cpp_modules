template <typename T>
Array<T>::Array() : _length(0) {
	this->_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int const length) : _length(length) {
	this->_array = new T[length];
}

template <typename T>
Array<T>::Array(Array<T> const & ref) {
	this->_length = ref._length;
	this->_array = new T[ref._length];
	for (int i = 0; i < (int)ref._length; i++)
		this->_array[i] = ref._array[i];
}

template <typename T>
Array<T>::~Array() {
	delete []this->_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const & ref) {
	if (this != &ref) {
		this->_length = ref._length;
		if (this->_array)
			delete []this->_array;

		this->_array = new T[ref._length];
		for (int i = 0; i < (int)ref._length; i++)
			this->_array[i] = ref._array[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= this->_length)
		throw (Array<T>::IndexOutOfBounds());

	return this->_array[index];
}

template <typename T>
void	Array<T>::display() const {
	for (int i = 0; i < (int)this->size(); i++) {
		std::cout << this->_array[i];
		if (i < (int)this->size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_length;
}

template <typename T>
const char*	Array<T>::IndexOutOfBounds::what() const throw() {
	return ("Index out of bounds!");
}
