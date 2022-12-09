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

		Fixed&	operator=(const Fixed &fixed);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		Fixed	operator+(const Fixed &ref);
		Fixed	operator-(const Fixed &ref);
		Fixed	operator*(const Fixed &ref);
		Fixed	operator/(const Fixed &ref);

		bool	operator>(const Fixed &ref) const;
		bool	operator<(const Fixed &ref) const;
		bool	operator>=(const Fixed &ref) const;
		bool	operator<=(const Fixed &ref) const;
		bool	operator==(const Fixed &ref) const;
		bool	operator!=(const Fixed &ref) const;

		int		getRawBits() const;
		void	setRawBits(const int raw);

		void	printNumber(std::ostream &flux) const;
		float	toFloat() const;
		int		toInt() const;

		static Fixed&		min(Fixed &fixed1, Fixed &fixed2);
		static Fixed&		max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed&	min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed&	max(const Fixed &fixed1, const Fixed &fixed2);

	private:
		static const int	_fractionalBits;

		int		_intNumber;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &fixed);

#endif