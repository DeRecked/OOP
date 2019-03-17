#include <iostream>
#include "card.hpp"

int main() {
	using Deck = std::vector<Card>;
 	
	Deck d1;
	Deck d2;

 	for (int s = Spades; s <= Hearts; s++) {
 		for (int r = Ace; r <= King; r++) {
			d1.emplace_back(static_cast<Rank>(r),
							static_cast<Suit>(s));
			d2.emplace_back(static_cast<Rank>(r),
							static_cast<Suit>(s));
		}
	}
	d2.emplace_back(static_cast<Color>(Red));
	d2.emplace_back(static_cast<Color>(Black));

	std::cout << "Deck (standard):\n" << d1 << std::endl;
	std::cout << "Deck (w/ joker):\n" << d2 << std::endl;
}
