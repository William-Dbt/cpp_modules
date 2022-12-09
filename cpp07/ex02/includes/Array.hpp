#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <exception>

template <typename T>
class	Array {
	public:
		Array();
		Array(unsigned int const length);
		Array(Array<T> const & ref);
		~Array();

		Array&	operator=(Array const & ref);
		T&		operator[](unsigned int index);

		void			display() const;
		unsigned int	size() const;

		class	IndexOutOfBounds : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		unsigned int	_length;
		T				*_array;
};

# include "Array.tpp"

#endif
