#ifndef	__FIXED_HPP__
# define __FIXED_HPP__

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();

		Fixed& operator=(const Fixed &fixed);
		int		getRawBits() const;
		void	setRawBits(const int raw);

	private:
		static const int	_cstIntNumber;

		int	_intNumber;
};

#endif