#pragma once

#include <iostream>

class Complex {
public:
	Complex(double real, double imag) :
		real_(real),
		imag_(imag) {}

	Complex add(Complex other) {
		return Complex(real_ + other.real_, imag_ + other.imag_);
	}

	Complex sub(Complex other) {
		return Complex(real_ - other.real_, imag_ - other.imag_);
	}

	// Not needed because we're using add and sub inside operators
	// friend Complex operator+(Complex lhs, Complex rhs);
	// friend Complex operator-(Complex lhs, Complex rhs);

	double getReal() const {
		return real_;
	}
	double getImaginary() const {
		return imag_;
	}

	void setReal(double real) {
		real_ = real;
	}
	void setImaginary(double imag) {
		imag_ = imag;
	}

private:
	double real_, imag_;
};

Complex operator+(Complex lhs, Complex rhs);
Complex operator-(Complex lhs, Complex rhs);

std::ostream& operator<<(std::ostream& stream, Complex rhs);

