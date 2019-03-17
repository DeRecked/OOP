#pragma once

#include <cassert>
#include <iosfwd>
#include <vector>


enum Rank {
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

enum Suit {
	Spades,
	Clubs,
	Diamonds,
	Hearts,
};

enum Color {
	Red,
	Black,
};


class Card {
private:
	// Private member
	int id;

public:
	// Default constructor
	Card(int n)
		: id(n)
	{ }

	// Virtual destructor
	virtual ~Card() = default;
	
	// Pure virtual function
	virtual Card* clone() = 0;
	//virtual Card* clone() { return new Card(*this); }

	// Accessor
	int getID() const { return id; }
};


class StandardCard : public Card {
private:
	// Private members
	Rank rank;
	Suit suit;

public:
	// Default constructor
	StandardCard(int n, Rank r, Suit s)
		: Card(n), rank(r), suit(s)
	{ }	  

	// Overidden virtual function
	Card* clone() override { return new StandardCard(*this); }
	
	// Accessors
	Rank getRank() const { return rank; }
	Suit getSuit() const { return suit; }
};


class JokerCard : public Card {
private:
	// Private member
	Color color;

public:
	// Default constructor
	JokerCard(int n, Color c)
		: Card(n), color(c)
	{ }

	// Overridden virtual function
	Card* clone() override { return new JokerCard(*this); }
	
	// Accessor
	Color getColor() const { return color; }
};

class Deck : std::vector<Card*> {
public:
	// Default constructor
	Deck(std::initializer_list<Card*> list)
		: std::vector<Card*>(list)
	{ }

	// Standard Deck constructor
	//Deck(std::initializer_list<StandardCard*> list)
	//	: std::vector<StandardCard*>(list)
	//{ }

	// Copy constructor
	Deck(const Deck& d) {
		for (Card* c : d)
			push_back(c->clone());
	}

	// Destructor
	~Deck() {
		for (Card* c : *this)
			delete c;
	}
};
