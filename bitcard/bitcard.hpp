#pragma once

// Four bits
enum Rank {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King,
};

// Two bits
enum Suit {
    Spades, Diamonds, Clubs, Hearts,
};

class Card {
public:
	// Default constructor
	Card() = default;

	// Construct and initialize
	Card(Rank r, Suit s)
		: bits((unsigned)s << 4 | (unsigned)r)
	{ }

	// Copy constructor
	Card(const Card& c) {
		bits = c.bits;
	}

	// Destructor
	~Card() {}

	// Accessors
	// Return rank
	Rank get_rank() const {
		return (Rank)(0b001111 & bits);
	}

	// Return suit
	Suit get_suit() const {
		return (Suit)((0b110000 & bits) >> 4);
	}

	// Equality operator overloads
	// Assuming we're comparing entire bitfield (rank AND suit)
	inline bool operator==(Card c) {
		return bits == c.bits;
	}

	inline bool operator!=(Card c) {
		return bits != c.bits;
	}

	// Friends
	// Ordering
	friend bool operator<(const Card& a, const Card& b) {
		return a.bits < b.bits;
	}

	friend bool operator>(const Card& a, const Card& b) {
		return a.bits > b.bits;
	}

private:
	unsigned char bits;	// 8-bits
};
