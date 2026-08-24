#include "MyInt.hpp"

std::ostream& operator<<(std::ostream& stream, const MyInt& rhs) {
	stream << rhs.x_;

	return stream;
}

