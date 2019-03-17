#include <iostream>
#include "string.hpp"

int main() {
	// Default construct
	String s0;

	// Construct and assign from a literal value
	String s1 = "hello";
	std::cout << "s1 should be \"hello\": " << s1 << std::endl;

	s1 = "foo";
	std::cout << "s1 should now be \"foo\": " << s1 << std::endl;

	// Copy construct and assign
	String s2 = s1;
	std::cout << "s2 should be \"foo\": " << s2 << std::endl;

	s2 = s1; // s2 == s1
	std::cout << "s2 should still be \"foo\": " << s2 << std::endl;

	// Compare
	if (s1 == s1)
		std::cout << "s1 == s1" << std::endl;
	else std::cout << "s1 != s1" << std::endl;

	// Order
	if (s1 < s1)	// lexicographical comparison
		std::cout << "s1 is less than s1" << std::endl;
	else std::cout << "s1 is not less than s1" << std::endl;

	// Object independence
	s2 = "bar"; // Does not change the value of s1
	std::cout << "s2 should now be \"bar\": " << s2 << std::endl;
}
