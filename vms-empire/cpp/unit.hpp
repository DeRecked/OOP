#pragma once

#include <algorithm>
#include <iosfwd>

class map;	// Forward declare map class so it can be accessed from Unit/Type classes

// Type of units
enum Type {
	ARMY,
	FIGHTER,
	PATROL,
	DESTROYER,
	SUBMARINE,
	TRANSPORT,
	CARRIER,
	BATTLESHIP,
	SATELLITE,
	NUM_OBJECTS,	// Number of unit types
	NO_PIECE,		// Null piece
};

// Commands for unit actions
enum Command {
	NONE,			// No action
	RANDOM,			// Move randomly
	SENTRY,			// Sleep
	FILL,			// Fill transport
	LAND,			// Land fighter at city
	EXPLORE,		// Explore nearby
	ARMYLOAD,		// Army moves toward/boards transport 
	ARMYATTACK,		// Looks for city to attack
	REPAIR,			// Ship moves toward port
	WFTRANSPORT,	// Army boards transport
	MOVE_N,			// Move in a direction
	MOVE_NE,
	MOVE_E,
	MOVE_SE,
	MOVE_S,
	MOVE_SW,
	MOVE_W,
	MOVE_NW,
};

// Directions for unit movement
enum Direction {
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST,
};

// Possible unit owners
enum Owner {
	Unowned,
	User,
	Computer,
};


// Unit struct contains all variables and functions that are global to all units
// Unit type specific variables and functions are in derived structes
class Unit {
	public:

	// Default constructor
	Unit(Owner o, Type t, int b, int h, int s, int m, int r, int c)
		: owner(o), type(t), build_time(b), hp(h), strength(s), moves(m), range(r), capacity(c)
	{ }

	// Unit commands
	// Pure virtual function
	virtual bool action(const Command c) = 0;

	// Accessors
	Owner get_owner() { return owner; }
	int get_build_time() { return build_time; }
	int get_hp() { return hp; }
	int get_strength() { return strength; }
	int get_moves() { return moves; }
	int get_range() { return range; }
	int get_capacity() { return capacity; }

	protected:

	// Mutators
	void set_owner(const Owner o) { this->owner = o; }
	void set_build_time(const int b) { this->build_time = b; }
	void set_hp(const int h) { this->hp = h; }
	void set_strength(const int s) { this->strength = s; }
	void set_moves(const int m) { this->moves = m; }
	void set_range(const int r) { this->range = r; }
	void set_capacity(const int c) { this->capacity = c; }

	// Carry out specific unit commands
	void random();
	void sentry();
	void fill();
	void land();
	void explore();
	void army_load();
	void army_attack();
	void repair();
	void wf_transport();
	void move(const Direction d);

	private:

	int parse_action(const Command c);
	void update_map();

	// Global unit properties
	Owner owner;	// Owner of unit
	Type type;		// Type of unit	
	int build_time;	// Time to build
	int strength;	// Attack power
	int hp;			// Health
	int moves;		// Moves unit can make per turn
	int range;		// Range of unit
	int capacity;	// Number of units this unit can hold
};


struct Army : public Unit {
	Army(Owner o, std::pair<int,int> loc)
		: Unit(o, ARMY, 5, 1, 1, 1, 0, 0),
			location(loc)
	{ }

    void action(const Command c) override;
	std::pair<int,int> location;	// Coordinates of unit
};

struct Fighter : public Unit {
	Fighter(Owner o, std::pair<int,int> loc)
		: Unit(o, FIGHTER, 10, 1, 1, 8, 32, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Patrol : public Unit {
	Patrol(Owner o, std::pair<int,int> loc)
		: Unit(o, PATROL, 15, 1, 1, 4, 0, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Destroyer : public Unit {
	Destroyer(Owner o, std::pair<int,int> loc)
		: Unit(o, DESTROYER, 20, 1, 3, 2, 0, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Submarine : public Unit {
	Submarine(Owner o, std::pair<int,int> loc)
		: Unit(o, SUBMARINE, 20, 3, 2, 2, 0, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Transport : public Unit {
	Transport(Owner o, std::pair<int,int> loc)
		: Unit(o, TRANSPORT, 30, 1, 1, 2, 0, 6),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Carrier : public Unit {
	Carrier(Owner o, std::pair<int,int> loc)
		: Unit(o, CARRIER, 30, 1, 8, 2, 0, 8),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Battleship : public Unit {
	Battleship(Owner o, std::pair<int,int> loc)
		: Unit(o, BATTLESHIP, 40, 2, 10, 2, 0, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};


struct Satellite : public Unit {
	Satellite(Owner o, std::pair<int,int> loc)
		: Unit(o, SATELLITE, 50, 0, 1, 10, 500, 0),
			location(loc)
	{ }

	void action(const Command c) override;
	std::pair<int,int> location;
};