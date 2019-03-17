#include "map.hpp"

bool Map::resize_map() {
        // Total size and number of cities
        map_size = height * width;
        num_cities = ((100 * (height + width)) / 228);

        // Create vector of vectors for map
        master_map.resize(width);
        player_map.resize(width);
        computer_map.resize(width);

        for (int y = 0; y < width; y++) {
            master_map[y].resize(height);
            player_map[y].resize(height);
            computer_map[y].resize(height);
        }
        
        // Add features to map
        populate_master_map();
        populate_player_map();
        populate_computer_map();
}

bool Map::populate_master_map() {
    char map_icons[3] = {land, sea, city};


}

bool Map::populate_player_map() {
    
    // Add fog of war
    for (int y = 0; y < width; y++)
        for (int x = 0; x < height; x++)
            player_map[y][x] = fow;
}

bool Map::populate_computer_map() {
    
    // Add fog of war
    for (int y = 0; y < width; y++)
        for (int x = 0; x < height; x++)
            computer_map[y][x] = fow;
}