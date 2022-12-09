#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <string>

class	Data {
	public:
		Data();
		Data(std::string const type);
		Data(Data const & ref);
		~Data();

		Data&		operator=(Data const & ref);
		std::string	getType() const;

	private:
		std::string	_type;
};

std::ostream&	operator<<(std::ostream& stream, Data const & ref);

#endif
