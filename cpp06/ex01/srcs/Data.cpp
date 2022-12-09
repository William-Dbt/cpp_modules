#include <iostream>
#include "Data.hpp"

Data::Data() : _type("Unknow") {}

Data::Data(std::string const type) : _type(type) {}

Data::Data(Data const & ref) {
	*this = ref;
}

Data::~Data() {}

Data&	Data::operator=(Data const & ref) {
	if (this != &ref)
		this->_type = ref._type;

	return *this;
}

std::string	Data::getType() const {
	return this->_type;
}

std::ostream&	operator<<(std::ostream& stream, Data const & ref) {
	stream << "Data object of \'" << ref.getType() << "\' type.";
	return stream;
}
