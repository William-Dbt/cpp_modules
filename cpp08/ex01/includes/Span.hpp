#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <exception>
# include <vector>
# include <iterator>
# include <algorithm>

class	Span {
	public:
		Span();
		Span(unsigned int size);
		Span(Span const & ref);
		~Span();

		Span&	operator=(Span const & ref);

		void			showArray();
		void			addNumber(unsigned int number);
		void			addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		unsigned int				getSize() const;
		std::vector<unsigned int>	getArray() const;

		class	SpanSlotFullException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class	NoSpanCanBeFoundException : public std::exception {
			public:
				const char*	what() const throw();
		};

	private:
		unsigned int				_size;
		std::vector<unsigned int>	_numbers;
};

#endif
