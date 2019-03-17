#include <iostream>
#include "bitcard.hpp"

int main() {
	// Default construct
	Card c0;

	// Construct and initialize
	Card c1(Ace, Spades);

	// Copy construct
	Card c2 = c1;

	if (c1 == c2)
		std::cout << "c1 == c2" << std::endl;	
	else std::cout << "c1 != c2" << std::endl;

	if (c1 < c2)
		std::cout << "c1 < c2" << std::endl;
	else std::cout << "c1 >= c2" << std::endl;

	if (c1 > c2)
		std::cout << "c1 > c2" << std::endl;
	else std::cout << "c1 <= c2" << std::endl;
}
