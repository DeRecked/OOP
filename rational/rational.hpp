// rational.hpp
#pragma once

#include <iosfwd>

class Rational {
	private:
	int num;	// Numerator
	int den;	// Denominator

	public:
	// Returns greatest common divisor
	int gcd(int a, int b) {
		if (b == 0)
			return a;
		else gcd(b, a % b);
	}

	// Constructor
	Rational(int n, int d) : num(n/gcd(n,d), den(d/gcd(n,d) { 
		if (d == 0)
			throw std::logic_error("invalid denominator");
	}

	// Equality
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator!=(const Rational& lhs, const Rational& rhs);

	// Ordering
	friend bool operator<(const Rational& lhs, const Rational& rhs);
	friend bool operator>(const Rational& lhs, const Rational& rhs);
	friend bool operator<=(const Rational& lhs, const Rational& rhs);
	friend bool operator>=(const Rational& lhs, const Rational& rhs);

	// Arithmetic
	friend Rational& operator+(const Rational& lhs, const Rational& rhs);
	friend Rational& operator-(const Rational& lhs, const Rational& rhs);
	friend Rational& operator*(const Rational& lhs, const Rational& rhs);
	friend Rational& operator/(const Rational& lhs, const Rational& rhs);

	// Input and output
	friend std::istream& operator>>(std::istream& stream, const Rational& in);
	friend std::ostream& operator<<(std::ostream& stream, const Rational& out);	
};

// Equality
inline bool operator==(const Rational& lhs, const Rational& rhs) {
	if ((lhs.num * rhs.den) == (lhs.den * rhs.num))
		return true;
	else return false;
}

inline bool operator!=(const Rational& lhs, const Rational& rhs) {
	return !(lhs == rhs);
}

// Ordering
inline bool operator<(const Rational& lhs, const Rational& rhs) {
	if ((lhs.num * rhs.den) < (lhs.den * rhs.num))
		return true;
	else return false;
}

inline bool operator>(const Rational& lhs, const Rational& rhs) {
	return (rhs < lhs)
}
	
inline bool operator<=(const Rational& lhs, const Rational& rhs) {
	return !(lhs > rhs);
}
	
inline bool operator>=(const Rational& lhs, const Rational& rhs) {
	return !(lhs < rhs);
}

// Arithmetic
inline Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational r;

	if (lhs.den == rhs.den) {
		r.num = lhs.num + rhs.num;
		r.den = lhs.den;
	}
	else {
		r.num = (lhs.num * rhs.den) + (rhs.num * lhs.den);
	    r.den = lhs.den * rhs.den;
	}
	return r;
}
	
inline Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational r;

	if (lhs.den == rhs.den) {
		r.num = lhs.num - rhs.num;
		r.den = lhs.den;
	}
	else {
		r.num = (lhs.num * rhs.den) - (rhs.num * lhs.den);
	    r.den = lhs.den * rhs.den;
	}
	return r;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational r;

	r.num = lhs.num * rhs.num;
	r.den = lhs.den * rhs.den;
	return r;
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational r;

	r.num = lhs.num * rhs.den;
	r.den = lhs.den * rhs.num;
	return r;
}

// Input and output
inline std::istream& operator>>(std::istream &stream, const Rational &in) {
	return stream >> in.num >> '/' >> in.den; 	
}

inline std::ostream& operator<<(std::ostream &stream, const Rational &out) {
	return stream << out.num << '/' << out.den;
}
