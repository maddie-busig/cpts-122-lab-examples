#include "Complex.hpp"

#include <iostream>

Complex operator+(Complex lhs, Complex rhs) {
	return lhs.add(rhs);
}
Complex operator-(Complex lhs, Complex rhs) {
	return lhs.sub(rhs);
}

std::ostream& operator<<(std::ostream& stream, Complex rhs) {
	stream << rhs.getReal() << '+' << rhs.getImaginary() << 'i';
	return stream;
}

