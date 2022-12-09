#include <iostream>
#include <cmath>
#include <iterator>
#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(Span const & ref) : _size(ref._size), _numbers(ref._numbers) {}

Span::~Span() {}

Span&	Span::operator=(Span const & ref) {
	if (this != &ref) {
		this->_size = ref._size;
		this->_numbers = ref._numbers;
	}
	return *this;
}

void	Span::showArray() {
	std::vector<unsigned int>::iterator	it = this->_numbers.begin();

	for (; it != this->_numbers.end(); it++)
		std::cout << *it << ' ';

	std::cout << std::endl;
}

void	Span::addNumber(unsigned int number) {
	if (this->_numbers.size() == this->_size)
		throw Span::SpanSlotFullException();

	this->_numbers.push_back(number);
}

void	Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end) {
	if (this->_numbers.size() + std::distance(begin, end) > this->_size)
		throw Span::SpanSlotFullException();

	std::vector<int>	vectorToAdd(begin, end);

	std::copy(vectorToAdd.begin(), vectorToAdd.end(), std::back_inserter(this->_numbers));
}

static bool	isSpanPossible(Span const & ref) {
	return (ref.getSize() > 1 && ref.getArray().size() > 1);
}

unsigned int	Span::shortestSpan() {
	unsigned int						shortestSpan, i;
	std::vector<unsigned int>			tmp = this->_numbers;
	std::vector<unsigned int>::iterator	it;

	if (!isSpanPossible(*this))
		throw Span::NoSpanCanBeFoundException();

	std::sort(tmp.begin(), tmp.end());
	shortestSpan = tmp[1] - tmp[0];
	for (it = tmp.begin(), i = 0; it != tmp.end(); ++it, ++i) {
		if (i < tmp.size() - 1 && (tmp[i + 1] - tmp[i]) < shortestSpan)
			shortestSpan = tmp[i + 1] - tmp[i];
	}
	return shortestSpan;
}

unsigned int	Span::longestSpan() {
	if (!isSpanPossible(*this))
		throw Span::NoSpanCanBeFoundException();

	return ((unsigned int)(*std::max_element(this->_numbers.begin(), this->_numbers.end()))
				- (unsigned int)(*std::min_element(this->_numbers.begin(), this->_numbers.end())));
}

unsigned int	Span::getSize() const {
	return this->_size;
}

std::vector<unsigned int>	Span::getArray() const {
	return this->_numbers;
}

const char*	Span::SpanSlotFullException::what() const throw() {
	return ("The span array is full!");
}

const char*	Span::NoSpanCanBeFoundException::what() const throw() {
	return ("No span can be found!");
}
