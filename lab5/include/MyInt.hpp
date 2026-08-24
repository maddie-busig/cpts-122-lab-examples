#ifndef MYINT_H
#define MYINT_H

#include <iostream>

class MyInt {
public:
	// Default constructor
	MyInt() : x_(0) {
	}
	// Constructor
	MyInt(int x) : x_(x) {
	}

	// Destructor, not needed for this simple example
	~MyInt() {
	}

	int getX() const {
		return x_;
	}
	void setX(int x) {
		x_ = x;
	}

	friend std::ostream& operator<<(std::ostream& stream, const MyInt& rhs);

private:
	int x_;
};

#endif

