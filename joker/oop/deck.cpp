#include <iostream>
#include "card.hpp"

int main() {
	std::cout << "Object Oriented class inheritance" << std::endl;
	
	// Create a basic card
	Card BasicCard(0);

	// Create a standard and joker card
	StandardCard AceOfSpades(0, Ace, Spades);
	JokerCard RedJoker(51, Red);
	
	// Create a deck of standard cards
	std::vector<StandardCard*> list;
	
	for (int n = 0; n < 52; n++)
		for (int r = Ace; r < King; r++)
			for (int s = Spades; s < Hearts; s++)
				list.push_back({
						static_cast<int>(n), 
						static_cast<Rank>(r), 
						static_cast<Suit>(s)
				});

	Deck deck(list);
}
