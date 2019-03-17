#pragma once

enum Rank {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King,
};

enum Suit {
    Clubs, Diamonds, Hearts, Spades,
};

// I want to do this:
//
//	Card c1{Ace, Spades}; // Construct from values
//	Card c2 = c1; // Copy constructor
//	c2 = c1; // Assignment operator
//	c1 == c2;
//	c1 != c2;
//

class Card {
	// Constructor to initialize rank/suit
	Card(Rank r, Suit s) 
		: rank(r), suit(s) 
	{}
  
	// A copy constructor ALWAYS has the following form (except when you're an expert).
	Card(const Card& c)
		: rank(c.rank), suit(c.suit)
	{}

	// A copy assignment ALWAYS has the following form:
	Card& operator=(const Card& c) {
		//rank = c.rank;
		//suit = c.suit;

		// The code above is equivalent to this:
		this->rank = c.rank;
		this->suit = c.suit;

		return *this;
	}

	// Destructor
	~Card() {}

private:
	Rank rank;
	Suit suit;
};

bool operator==(Card a, Card b) {
	return a.rank == b.rank && a.suit == b.suit;
}

bool operator!=(Card a, Card b) {
	return !(a == b);
}
