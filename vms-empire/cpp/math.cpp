// Include standard libraries
#include <algorithm>
#include <cmath>
#include <ctime>

// Include custom libraries
//#include "empire.hpp"
//#include "extern.hpp"

// Seed srand
void init_rand() {
	srand((unsigned)(time(NULL) & 0xFFFF));
}

// Return random integer from 0 to n-1
long irand(long n) {

	if (n < 2)
		return 0;
	return (rand() % n);
}

// Return random integer between a and b
int rndint(int a, int b) {
	int size = b - a + 1;
	return ((rand() % size) + a);
}

// Return distance between two locations
int dist(loc_t a, loc_t b) {
	int ax = loc_row (a);
	int ay = loc_col (a);
	int bx = loc_row (b);
	int by = loc_col (b);

	return std::max(abs(ax-bx), abs(ay-by));
};

// Return square root of integer
int isqrt(int n) {
	return static_cast<int>(floor(sqrt(n)));
