#ifndef __SERIALIZE_HPP__
# define __SERIALIZE_HPP__

# include <stdint.h>
# include "Data.hpp"

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
