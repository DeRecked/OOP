#include <algorithm>
#include <iostream>
#include "map.hpp"
#include "unit.hpp"

int main(int argv, char** argc) {
    // Create map
    Map m;

    // Create unit on map
    std::pair<int,int> coords(0,0);
    Army a1(User, coords);

    std::cout << "Created an Army\n";
    std::cout << "Owner: " << a1.get_owner() << '\n';
    std::cout << "Location: " << a1.location.first << "," << a1.location.second << "\n";
    std::cout << "Build Time: " << a1.get_build_time() << '\n';
    std::cout << "Strength: " << a1.get_strength() << '\n';
    std::cout << "HP: " << a1.get_hp() << '\n';
    std::cout << "Moves: " << a1.get_moves() << '\n';
    std::cout << "Range: " << a1.get_range() << '\n';
    std::cout << "Capacity: " << a1.get_capacity() << '\n';
    std::cout << std::endl;

    a1.action(SENTRY);
    a1.action(MOVE_S);

    Unit u;

    return 0;
}