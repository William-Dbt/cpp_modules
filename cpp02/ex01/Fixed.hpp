#ifndef	__FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &fixed);
		~Fixed();

		int		getRawBits() const;
		Fixed&	operator=(const Fixed &fixed);

		void	setRawBits(const int raw);
		void	printNumber(std::ostream &flux) const;
		float	toFloat() const;
		int		toInt() const;

	private:
		static const int	_fractionalBits;

		int		_intNumber;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &fixed);

#endif